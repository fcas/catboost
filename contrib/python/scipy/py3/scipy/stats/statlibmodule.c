/* File: statlibmodule.c
 * This file is auto-generated with f2py (version:1.24.4).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Sun Apr 25 21:13:50 2021
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */

/* Unconditionally included */
#include <Python.h>
#include <numpy/npy_os.h>

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *statlib_error;
static PyObject *statlib_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

/* See fortranobject.h for definitions. The macros here are provided for BC. */
#define rank f2py_rank
#define shape f2py_shape
#define fshape f2py_shape
#define len f2py_len
#define flen f2py_flen
#define slen f2py_slen
#define size f2py_size

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(statlib_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int
int_from_pyobj(int* v, PyObject *obj, const char *errmess)
{
    PyObject* tmp = NULL;

    if (PyLong_Check(obj)) {
        *v = Npy__PyLong_AsInt(obj);
        return !(*v == -1 && PyErr_Occurred());
    }

    tmp = PyNumber_Long(obj);
    if (tmp) {
        *v = Npy__PyLong_AsInt(tmp);
        Py_DECREF(tmp);
        return !(*v == -1 && PyErr_Occurred());
    }

    if (PyComplex_Check(obj)) {
        PyErr_Clear();
        tmp = PyObject_GetAttrString(obj,"real");
    }
    else if (PyBytes_Check(obj) || PyUnicode_Check(obj)) {
        /*pass*/;
    }
    else if (PySequence_Check(obj)) {
        PyErr_Clear();
        tmp = PySequence_GetItem(obj, 0);
    }

    if (tmp) {
        if (int_from_pyobj(v, tmp, errmess)) {
            Py_DECREF(tmp);
            return 1;
        }
        Py_DECREF(tmp);
    }

    {
        PyObject* err = PyErr_Occurred();
        if (err == NULL) {
            err = statlib_error;
        }
        PyErr_SetString(err, errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(swilk,SWILK)(int*,float*,int*,int*,int*,float*,float*,float*,int*);
extern void F_FUNC(gscale,GSCALE)(int*,int*,float*,float*,int*,float*,float*,int*);
extern double F_FUNC(prho,PRHO)(int*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/*********************************** swilk ***********************************/
static char doc_f2py_rout_statlib_swilk[] = "\
a,w,pw,ifault = swilk(x,a,[init,n1])\n\nWrapper for ``swilk``.\
\n\nParameters\n----------\n"
"x : input rank-1 array('f') with bounds (n)\n"
"a : input rank-1 array('f') with bounds (n2)\n"
"\nOther Parameters\n----------------\n"
"init : input int, optional\n    Default: 0\n"
"n1 : input int, optional\n    Default: n\n"
"\nReturns\n-------\n"
"a : rank-1 array('f') with bounds (n2)\n"
"w : float\n"
"pw : float\n"
"ifault : int";
/* extern void F_FUNC(swilk,SWILK)(int*,float*,int*,int*,int*,float*,float*,float*,int*); */
static PyObject *f2py_rout_statlib_swilk(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,float*,int*,int*,int*,float*,float*,float*,int*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    int init = 0;
    PyObject *init_capi = Py_None;
    float *x = NULL;
    npy_intp x_Dims[1] = {-1};
    const int x_Rank = 1;
    PyArrayObject *capi_x_as_array = NULL;
    int capi_x_intent = 0;
    PyObject *x_capi = Py_None;
    int n = 0;
    int n1 = 0;
    PyObject *n1_capi = Py_None;
    int n2 = 0;
    float *a = NULL;
    npy_intp a_Dims[1] = {-1};
    const int a_Rank = 1;
    PyArrayObject *capi_a_as_array = NULL;
    int capi_a_intent = 0;
    PyObject *a_capi = Py_None;
    float w = 0;
    float pw = 0;
    int ifault = 0;
    static char *capi_kwlist[] = {"x","a","init","n1",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OO|OO:statlib.swilk",\
        capi_kwlist,&x_capi,&a_capi,&init_capi,&n1_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable init */
    if (init_capi == Py_None) init = 0; else
        init = (int)PyObject_IsTrue(init_capi);
        f2py_success = 1;
    if (f2py_success) {
    /* Processing variable x */
    ;
    capi_x_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "statlib.statlib.swilk: failed to create array from the 1st argument `x`";
    capi_x_as_array = ndarray_from_pyobj(  NPY_FLOAT,1,x_Dims,x_Rank,  capi_x_intent,x_capi,capi_errmess);
    if (capi_x_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = statlib_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        x = (float *)(PyArray_DATA(capi_x_as_array));

    /* Processing variable w */
    /* Processing variable pw */
    /* Processing variable ifault */
    /* Processing variable n */
    n = shape(x,0);
    /* Processing variable n1 */
    if (n1_capi == Py_None) n1 = n; else
        f2py_success = int_from_pyobj(&n1,n1_capi,"statlib.swilk() 2nd keyword (n1) can't be converted to int");
    if (f2py_success) {
    CHECKSCALAR(n1<=n,"n1<=n","2nd keyword n1","swilk:n1=%d",n1) {
    /* Processing variable n2 */
    n2 = n/2;
    /* Processing variable a */
    a_Dims[0]=n2;
    capi_a_intent |= F2PY_INTENT_IN|F2PY_INTENT_OUT;
    const char * capi_errmess = "statlib.statlib.swilk: failed to create array from the 2nd argument `a`";
    capi_a_as_array = ndarray_from_pyobj(  NPY_FLOAT,1,a_Dims,a_Rank,  capi_a_intent,a_capi,capi_errmess);
    if (capi_a_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = statlib_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        a = (float *)(PyArray_DATA(capi_a_as_array));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(&init,x,&n,&n1,&n2,a,&w,&pw,&ifault);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("Nffi",capi_a_as_array,w,pw,ifault);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    }  /* if (capi_a_as_array == NULL) ... else of a */
    /* End of cleaning variable a */
    /* End of cleaning variable n2 */
    } /*CHECKSCALAR(n1<=n)*/
    } /*if (f2py_success) of n1*/
    /* End of cleaning variable n1 */
    /* End of cleaning variable n */
    /* End of cleaning variable ifault */
    /* End of cleaning variable pw */
    /* End of cleaning variable w */
    if((PyObject *)capi_x_as_array!=x_capi) {
        Py_XDECREF(capi_x_as_array); }
    }  /* if (capi_x_as_array == NULL) ... else of x */
    /* End of cleaning variable x */
    } /*if (f2py_success) of init*/
    /* End of cleaning variable init */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************** end of swilk ********************************/

/*********************************** gscale ***********************************/
static char doc_f2py_rout_statlib_gscale[] = "\
astart,a1,ifault = gscale(test,other)\n\nWrapper for ``gscale``.\
\n\nParameters\n----------\n"
"test : input int\n"
"other : input int\n"
"\nReturns\n-------\n"
"astart : float\n"
"a1 : rank-1 array('f') with bounds (l1)\n"
"ifault : int";
/* extern void F_FUNC(gscale,GSCALE)(int*,int*,float*,float*,int*,float*,float*,int*); */
static PyObject *f2py_rout_statlib_gscale(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,float*,float*,int*,float*,float*,int*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    int test = 0;
    PyObject *test_capi = Py_None;
    int other = 0;
    PyObject *other_capi = Py_None;
    float astart = 0;
    float *a1 = NULL;
    npy_intp a1_Dims[1] = {-1};
    const int a1_Rank = 1;
    PyArrayObject *capi_a1_as_array = NULL;
    int capi_a1_intent = 0;
    int l1 = 0;
    float *a2 = NULL;
    npy_intp a2_Dims[1] = {-1};
    const int a2_Rank = 1;
    PyArrayObject *capi_a2_as_array = NULL;
    int capi_a2_intent = 0;
    float *a3 = NULL;
    npy_intp a3_Dims[1] = {-1};
    const int a3_Rank = 1;
    PyArrayObject *capi_a3_as_array = NULL;
    int capi_a3_intent = 0;
    int ifault = 0;
    static char *capi_kwlist[] = {"test","other",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OO|:statlib.gscale",\
        capi_kwlist,&test_capi,&other_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable test */
        f2py_success = int_from_pyobj(&test,test_capi,"statlib.gscale() 1st argument (test) can't be converted to int");
    if (f2py_success) {
    /* Processing variable other */
        f2py_success = int_from_pyobj(&other,other_capi,"statlib.gscale() 2nd argument (other) can't be converted to int");
    if (f2py_success) {
    /* Processing variable astart */
    /* Processing variable ifault */
    /* Processing variable l1 */
    l1 = (1+(test*other)/2);
    /* Processing variable a2 */
    a2_Dims[0]=l1;
    capi_a2_intent |= F2PY_INTENT_HIDE;
    const char * capi_errmess = "statlib.statlib.gscale: failed to create array from the hidden `a2`";
    capi_a2_as_array = ndarray_from_pyobj(  NPY_FLOAT,1,a2_Dims,a2_Rank,  capi_a2_intent,Py_None,capi_errmess);
    if (capi_a2_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = statlib_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        a2 = (float *)(PyArray_DATA(capi_a2_as_array));

    /* Processing variable a3 */
    a3_Dims[0]=l1;
    capi_a3_intent |= F2PY_INTENT_HIDE;
    const char * capi_errmess = "statlib.statlib.gscale: failed to create array from the hidden `a3`";
    capi_a3_as_array = ndarray_from_pyobj(  NPY_FLOAT,1,a3_Dims,a3_Rank,  capi_a3_intent,Py_None,capi_errmess);
    if (capi_a3_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = statlib_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        a3 = (float *)(PyArray_DATA(capi_a3_as_array));

    /* Processing variable a1 */
    a1_Dims[0]=l1;
    capi_a1_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
    const char * capi_errmess = "statlib.statlib.gscale: failed to create array from the hidden `a1`";
    capi_a1_as_array = ndarray_from_pyobj(  NPY_FLOAT,1,a1_Dims,a1_Rank,  capi_a1_intent,Py_None,capi_errmess);
    if (capi_a1_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = statlib_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        a1 = (float *)(PyArray_DATA(capi_a1_as_array));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(&test,&other,&astart,a1,&l1,a2,a3,&ifault);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("fNi",astart,capi_a1_as_array,ifault);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    }  /* if (capi_a1_as_array == NULL) ... else of a1 */
    /* End of cleaning variable a1 */
        Py_XDECREF(capi_a3_as_array);
    }  /* if (capi_a3_as_array == NULL) ... else of a3 */
    /* End of cleaning variable a3 */
        Py_XDECREF(capi_a2_as_array);
    }  /* if (capi_a2_as_array == NULL) ... else of a2 */
    /* End of cleaning variable a2 */
    /* End of cleaning variable l1 */
    /* End of cleaning variable ifault */
    /* End of cleaning variable astart */
    } /*if (f2py_success) of other*/
    /* End of cleaning variable other */
    } /*if (f2py_success) of test*/
    /* End of cleaning variable test */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of gscale *******************************/

/************************************ prho ************************************/
static char doc_f2py_rout_statlib_prho[] = "\
ifault = prho(n,is)\n\nWrapper for ``prho``.\
\n\nParameters\n----------\n"
"n : input int\n"
"is : input int\n"
"\nReturns\n-------\n"
"prho : float\n"
"ifault : int";
/* extern double F_FUNC(prho,PRHO)(int*,int*,int*); */
static PyObject *f2py_rout_statlib_prho(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           double (*f2py_func)(int*,int*,int*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    double prho_return_value=0;
    int n = 0;
    PyObject *n_capi = Py_None;
    int is = 0;
    PyObject *is_capi = Py_None;
    int ifault = 0;
    static char *capi_kwlist[] = {"n","is",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OO|:statlib.prho",\
        capi_kwlist,&n_capi,&is_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable n */
        f2py_success = int_from_pyobj(&n,n_capi,"statlib.prho() 1st argument (n) can't be converted to int");
    if (f2py_success) {
    /* Processing variable is */
        f2py_success = int_from_pyobj(&is,is_capi,"statlib.prho() 2nd argument (is) can't be converted to int");
    if (f2py_success) {
    /* Processing variable ifault */
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
    prho_return_value = (*f2py_func)(&n,&is,&ifault);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("i",ifault);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    /* End of cleaning variable ifault */
    } /*if (f2py_success) of is*/
    /* End of cleaning variable is */
    } /*if (f2py_success) of n*/
    /* End of cleaning variable n */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************** end of prho ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
    {"swilk",-1,{{-1}},0,0,(char *)  F_FUNC(swilk,SWILK),  (f2py_init_func)f2py_rout_statlib_swilk,doc_f2py_rout_statlib_swilk},
    {"gscale",-1,{{-1}},0,0,(char *)  F_FUNC(gscale,GSCALE),  (f2py_init_func)f2py_rout_statlib_gscale,doc_f2py_rout_statlib_gscale},
    {"prho",-1,{{-1}},0,0,(char *)  F_FUNC(prho,PRHO),  (f2py_init_func)f2py_rout_statlib_prho,doc_f2py_rout_statlib_prho},

/*eof routine_defs*/
    {NULL}
};

static PyMethodDef f2py_module_methods[] = {

    {NULL,NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "statlib",
    NULL,
    -1,
    f2py_module_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_statlib(void) {
    int i;
    PyObject *m,*d, *s, *tmp;
    m = statlib_module = PyModule_Create(&moduledef);
    Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
    import_array();
    if (PyErr_Occurred())
        {PyErr_SetString(PyExc_ImportError, "can't initialize module statlib (failed to import numpy)"); return m;}
    d = PyModule_GetDict(m);
    s = PyUnicode_FromString("1.24.4");
    PyDict_SetItemString(d, "__version__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString(
        "This module 'statlib' is auto-generated with f2py (version:1.24.4).\nFunctions:\n"
"    a,w,pw,ifault = swilk(x,a,init=0,n1=n)\n"
"    astart,a1,ifault = gscale(test,other)\n"
"    ifault = prho(n,is)\n"
".");
    PyDict_SetItemString(d, "__doc__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString("1.24.4");
    PyDict_SetItemString(d, "__f2py_numpy_version__", s);
    Py_DECREF(s);
    statlib_error = PyErr_NewException ("statlib.error", NULL, NULL);
    /*
     * Store the error object inside the dict, so that it could get deallocated.
     * (in practice, this is a module, so it likely will not and cannot.)
     */
    PyDict_SetItemString(d, "_statlib_error", statlib_error);
    Py_DECREF(statlib_error);
    for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }



/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
    if (! PyErr_Occurred())
        on_exit(f2py_report_on_exit,(void*)"statlib");
#endif
    return m;
}
#ifdef __cplusplus
}
#endif
