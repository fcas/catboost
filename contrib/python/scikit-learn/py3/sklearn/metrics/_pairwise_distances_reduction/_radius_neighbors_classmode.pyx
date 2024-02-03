import warnings

from cython cimport floating, final, integral
from cython.operator cimport dereference as deref
from cython.parallel cimport parallel, prange
from ._classmode cimport WeightingStrategy
from ...utils._typedefs cimport intp_t, float64_t

import numpy as np
from scipy.sparse import issparse
from ...utils.fixes import threadpool_limits

from ._radius_neighbors cimport RadiusNeighbors32
from ._datasets_pair cimport DatasetsPair32

cdef class RadiusNeighborsClassMode32(RadiusNeighbors32):
    """
    32bit implementation of RadiusNeighborsClassMode.
    """
    cdef:
        const intp_t[::1] Y_labels
        const intp_t[::1] unique_Y_labels
        intp_t outlier_label_index
        bint outlier_label_exists
        bint outliers_exist
        unsigned char[::1] outliers
        object outlier_label
        float64_t[:, ::1] class_scores
        WeightingStrategy weight_type

    @classmethod
    def compute(
        cls,
        X,
        Y,
        float64_t radius,
        weights,
        Y_labels,
        unique_Y_labels,
        outlier_label=None,
        str metric="euclidean",
        chunk_size=None,
        dict metric_kwargs=None,
        str strategy=None,
    ):
        # Use a generic implementation that handles most scipy
        # metrics by computing the distances between 2 vectors at a time.
        pda = RadiusNeighborsClassMode32(
            datasets_pair=DatasetsPair32.get_for(X, Y, metric, metric_kwargs),
            radius=radius,
            chunk_size=chunk_size,
            strategy=strategy,
            weights=weights,
            Y_labels=Y_labels,
            unique_Y_labels=unique_Y_labels,
            outlier_label=outlier_label,
        )

        # Limit the number of threads in second level of nested parallelism for BLAS
        # to avoid threads over-subscription (in GEMM for instance).
        with threadpool_limits(limits=1, user_api="blas"):
            if pda.execute_in_parallel_on_Y:
                pda._parallel_on_Y()
            else:
                pda._parallel_on_X()

        return pda._finalize_results()

    def __init__(
        self,
        DatasetsPair32 datasets_pair,
        const intp_t[::1] Y_labels,
        const intp_t[::1] unique_Y_labels,
        float64_t radius,
        chunk_size=None,
        strategy=None,
        weights=None,
        outlier_label=None,
    ):
        super().__init__(
            datasets_pair=datasets_pair,
            chunk_size=chunk_size,
            strategy=strategy,
            radius=radius,
        )

        if weights == "uniform":
            self.weight_type = WeightingStrategy.uniform
        elif weights == "distance":
            self.weight_type = WeightingStrategy.distance
        else:
            self.weight_type = WeightingStrategy.callable

        self.Y_labels = Y_labels
        self.unique_Y_labels = unique_Y_labels
        self.outlier_label_index = -1
        self.outliers_exist = False
        self.outlier_label = outlier_label
        self.outliers = np.zeros(self.n_samples_X, dtype=np.bool_)

        cdef intp_t idx
        if self.outlier_label is not None:
            for idx in range(self.unique_Y_labels.shape[0]):
                if self.unique_Y_labels[idx] == outlier_label:
                    self.outlier_label_index = idx

        # Map from set of unique labels to their indices in `class_scores`
        # Buffer used in building a histogram for one-pass weighted mode
        self.class_scores = np.zeros(
            (self.n_samples_X, unique_Y_labels.shape[0]), dtype=np.float64,
        )


    cdef inline void weighted_histogram_mode(
        self,
        intp_t sample_index,
        intp_t sample_n_neighbors,
        intp_t* indices,
        float64_t* distances,
    ) noexcept nogil:
        cdef:
            intp_t neighbor_idx, neighbor_class_idx, label_index
            float64_t score_incr = 1
            bint use_distance_weighting = (
                self.weight_type == WeightingStrategy.distance
            )

        if sample_n_neighbors == 0:
            self.outliers_exist = True
            self.outliers[sample_index] = True
            if self.outlier_label_index >= 0:
                self.class_scores[sample_index][self.outlier_label_index] = score_incr

            return

        # Iterate over the neighbors. This can be different for
        # each of the samples as they are based on the radius.
        for neighbor_rank in range(sample_n_neighbors):
            if use_distance_weighting:
                score_incr = 1 / distances[neighbor_rank]

            neighbor_idx = indices[neighbor_rank]
            neighbor_class_idx = self.Y_labels[neighbor_idx]
            self.class_scores[sample_index][neighbor_class_idx] += score_incr

        return

    @final
    cdef void _parallel_on_X_prange_iter_finalize(
        self,
        intp_t thread_num,
        intp_t X_start,
        intp_t X_end,
    ) noexcept nogil:
        cdef:
            intp_t idx

        for idx in range(X_start, X_end):
            self.weighted_histogram_mode(
                sample_index=idx,
                sample_n_neighbors=deref(self.neigh_indices)[idx].size(),
                indices=deref(self.neigh_indices)[idx].data(),
                distances=deref(self.neigh_distances)[idx].data(),
            )

        return

    @final
    cdef void _parallel_on_Y_finalize(
        self,
    ) noexcept nogil:
        cdef:
            intp_t idx

        with nogil, parallel(num_threads=self.effective_n_threads):
            # Merge vectors used in threads into the main ones.
            # This is done in parallel sample-wise (no need for locks).
            for idx in prange(self.n_samples_X, schedule='static'):
                self._merge_vectors(idx, self.chunks_n_threads)

            for idx in prange(self.n_samples_X, schedule='static'):
                self.weighted_histogram_mode(
                    sample_index=idx,
                    sample_n_neighbors=deref(self.neigh_indices)[idx].size(),
                    indices=deref(self.neigh_indices)[idx].data(),
                    distances=deref(self.neigh_distances)[idx].data(),
                )

        return

    def _finalize_results(self):
        if self.outliers_exist and self.outlier_label is None:
            raise ValueError(
                "No neighbors found for test samples %r, "
                "you can try using larger radius, "
                "giving a label for outliers, "
                "or considering removing them from your dataset."
                % np.where(self.outliers)[0]
            )

        if self.outliers_exist and self.outlier_label_index < 0:
            warnings.warn(
                "Outlier label %s is not in training "
                "classes. All class probabilities of "
                "outliers will be assigned with 0."
                % self.outlier_label
            )

        probabilities = np.asarray(self.class_scores)
        normalizer = probabilities.sum(axis=1, keepdims=True)
        normalizer[normalizer == 0.0] = 1.0
        probabilities /= normalizer
        return probabilities
from ._radius_neighbors cimport RadiusNeighbors64
from ._datasets_pair cimport DatasetsPair64

cdef class RadiusNeighborsClassMode64(RadiusNeighbors64):
    """
    64bit implementation of RadiusNeighborsClassMode.
    """
    cdef:
        const intp_t[::1] Y_labels
        const intp_t[::1] unique_Y_labels
        intp_t outlier_label_index
        bint outlier_label_exists
        bint outliers_exist
        unsigned char[::1] outliers
        object outlier_label
        float64_t[:, ::1] class_scores
        WeightingStrategy weight_type

    @classmethod
    def compute(
        cls,
        X,
        Y,
        float64_t radius,
        weights,
        Y_labels,
        unique_Y_labels,
        outlier_label=None,
        str metric="euclidean",
        chunk_size=None,
        dict metric_kwargs=None,
        str strategy=None,
    ):
        # Use a generic implementation that handles most scipy
        # metrics by computing the distances between 2 vectors at a time.
        pda = RadiusNeighborsClassMode64(
            datasets_pair=DatasetsPair64.get_for(X, Y, metric, metric_kwargs),
            radius=radius,
            chunk_size=chunk_size,
            strategy=strategy,
            weights=weights,
            Y_labels=Y_labels,
            unique_Y_labels=unique_Y_labels,
            outlier_label=outlier_label,
        )

        # Limit the number of threads in second level of nested parallelism for BLAS
        # to avoid threads over-subscription (in GEMM for instance).
        with threadpool_limits(limits=1, user_api="blas"):
            if pda.execute_in_parallel_on_Y:
                pda._parallel_on_Y()
            else:
                pda._parallel_on_X()

        return pda._finalize_results()

    def __init__(
        self,
        DatasetsPair64 datasets_pair,
        const intp_t[::1] Y_labels,
        const intp_t[::1] unique_Y_labels,
        float64_t radius,
        chunk_size=None,
        strategy=None,
        weights=None,
        outlier_label=None,
    ):
        super().__init__(
            datasets_pair=datasets_pair,
            chunk_size=chunk_size,
            strategy=strategy,
            radius=radius,
        )

        if weights == "uniform":
            self.weight_type = WeightingStrategy.uniform
        elif weights == "distance":
            self.weight_type = WeightingStrategy.distance
        else:
            self.weight_type = WeightingStrategy.callable

        self.Y_labels = Y_labels
        self.unique_Y_labels = unique_Y_labels
        self.outlier_label_index = -1
        self.outliers_exist = False
        self.outlier_label = outlier_label
        self.outliers = np.zeros(self.n_samples_X, dtype=np.bool_)

        cdef intp_t idx
        if self.outlier_label is not None:
            for idx in range(self.unique_Y_labels.shape[0]):
                if self.unique_Y_labels[idx] == outlier_label:
                    self.outlier_label_index = idx

        # Map from set of unique labels to their indices in `class_scores`
        # Buffer used in building a histogram for one-pass weighted mode
        self.class_scores = np.zeros(
            (self.n_samples_X, unique_Y_labels.shape[0]), dtype=np.float64,
        )


    cdef inline void weighted_histogram_mode(
        self,
        intp_t sample_index,
        intp_t sample_n_neighbors,
        intp_t* indices,
        float64_t* distances,
    ) noexcept nogil:
        cdef:
            intp_t neighbor_idx, neighbor_class_idx, label_index
            float64_t score_incr = 1
            bint use_distance_weighting = (
                self.weight_type == WeightingStrategy.distance
            )

        if sample_n_neighbors == 0:
            self.outliers_exist = True
            self.outliers[sample_index] = True
            if self.outlier_label_index >= 0:
                self.class_scores[sample_index][self.outlier_label_index] = score_incr

            return

        # Iterate over the neighbors. This can be different for
        # each of the samples as they are based on the radius.
        for neighbor_rank in range(sample_n_neighbors):
            if use_distance_weighting:
                score_incr = 1 / distances[neighbor_rank]

            neighbor_idx = indices[neighbor_rank]
            neighbor_class_idx = self.Y_labels[neighbor_idx]
            self.class_scores[sample_index][neighbor_class_idx] += score_incr

        return

    @final
    cdef void _parallel_on_X_prange_iter_finalize(
        self,
        intp_t thread_num,
        intp_t X_start,
        intp_t X_end,
    ) noexcept nogil:
        cdef:
            intp_t idx

        for idx in range(X_start, X_end):
            self.weighted_histogram_mode(
                sample_index=idx,
                sample_n_neighbors=deref(self.neigh_indices)[idx].size(),
                indices=deref(self.neigh_indices)[idx].data(),
                distances=deref(self.neigh_distances)[idx].data(),
            )

        return

    @final
    cdef void _parallel_on_Y_finalize(
        self,
    ) noexcept nogil:
        cdef:
            intp_t idx

        with nogil, parallel(num_threads=self.effective_n_threads):
            # Merge vectors used in threads into the main ones.
            # This is done in parallel sample-wise (no need for locks).
            for idx in prange(self.n_samples_X, schedule='static'):
                self._merge_vectors(idx, self.chunks_n_threads)

            for idx in prange(self.n_samples_X, schedule='static'):
                self.weighted_histogram_mode(
                    sample_index=idx,
                    sample_n_neighbors=deref(self.neigh_indices)[idx].size(),
                    indices=deref(self.neigh_indices)[idx].data(),
                    distances=deref(self.neigh_distances)[idx].data(),
                )

        return

    def _finalize_results(self):
        if self.outliers_exist and self.outlier_label is None:
            raise ValueError(
                "No neighbors found for test samples %r, "
                "you can try using larger radius, "
                "giving a label for outliers, "
                "or considering removing them from your dataset."
                % np.where(self.outliers)[0]
            )

        if self.outliers_exist and self.outlier_label_index < 0:
            warnings.warn(
                "Outlier label %s is not in training "
                "classes. All class probabilities of "
                "outliers will be assigned with 0."
                % self.outlier_label
            )

        probabilities = np.asarray(self.class_scores)
        normalizer = probabilities.sum(axis=1, keepdims=True)
        normalizer[normalizer == 0.0] = 1.0
        probabilities /= normalizer
        return probabilities
