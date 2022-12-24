/* File: _test_odeint_bandedmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Mon Jan 20 20:54:49 2020
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_test_odeint_banded_error;
static PyObject *_test_odeint_banded_module;

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

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

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

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(_test_odeint_banded_error,errstring);\
        /*goto capi_fail;*/\
    } else 

/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if (tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _test_odeint_banded_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _test_odeint_banded_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(getbands,GETBANDS)(double*);
extern void F_FUNC(banded5x5,BANDED5X5)(int*,double*,double*,double*);
extern void F_FUNC_US(banded5x5_jac,BANDED5X5_JAC)(int*,double*,double*,int*,int*,double*,int*);
extern void F_FUNC_US(banded5x5_bjac,BANDED5X5_BJAC)(int*,double*,double*,int*,int*,double*,int*);
extern void F_FUNC_US(banded5x5_solve,BANDED5X5_SOLVE)(double*,int*,double*,int*,int*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** getbands **********************************/
static char doc_f2py_rout__test_odeint_banded_getbands[] = "\
jac = getbands()\n\nWrapper for ``getbands``.\
\n\nReturns\n-------\n"
"jac : rank-2 array('d') with bounds (4,5)";
/* extern void F_FUNC(getbands,GETBANDS)(double*); */
static PyObject *f2py_rout__test_odeint_banded_getbands(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *jac = NULL;
  npy_intp jac_Dims[2] = {-1, -1};
  const int jac_Rank = 2;
  PyArrayObject *capi_jac_tmp = NULL;
  int capi_jac_intent = 0;
  static char *capi_kwlist[] = {NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    ":_test_odeint_banded.getbands",\
    capi_kwlist))
    return NULL;
/*frompyobj*/
  /* Processing variable jac */
  jac_Dims[0]=4,jac_Dims[1]=5;
  capi_jac_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_jac_tmp = array_from_pyobj(NPY_DOUBLE,jac_Dims,jac_Rank,capi_jac_intent,Py_None);
  if (capi_jac_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting hidden `jac' of _test_odeint_banded.getbands to C/Fortran array" );
  } else {
    jac = (double *)(PyArray_DATA(capi_jac_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(jac);
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
    capi_buildvalue = Py_BuildValue("N",capi_jac_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_jac_tmp == NULL) ... else of jac*/
  /* End of cleaning variable jac */
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
/****************************** end of getbands ******************************/

/********************************* banded5x5 *********************************/
static char doc_f2py_rout__test_odeint_banded_banded5x5[] = "\
banded5x5(t,y,f,[n])\n\nWrapper for ``banded5x5``.\
\n\nParameters\n----------\n"
"t : input float\n"
"y : input rank-1 array('d') with bounds (n)\n"
"f : input rank-1 array('d') with bounds (n)\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(y)";
/* extern void F_FUNC(banded5x5,BANDED5X5)(int*,double*,double*,double*); */
static PyObject *f2py_rout__test_odeint_banded_banded5x5(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  double t = 0;
  PyObject *t_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[1] = {-1};
  const int y_Rank = 1;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  double *f = NULL;
  npy_intp f_Dims[1] = {-1};
  const int f_Rank = 1;
  PyArrayObject *capi_f_tmp = NULL;
  int capi_f_intent = 0;
  PyObject *f_capi = Py_None;
  static char *capi_kwlist[] = {"t","y","f","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOO|O:_test_odeint_banded.banded5x5",\
    capi_kwlist,&t_capi,&y_capi,&f_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable t */
    f2py_success = double_from_pyobj(&t,t_capi,"_test_odeint_banded.banded5x5() 1st argument (t) can't be converted to double");
  if (f2py_success) {
  /* Processing variable y */
  ;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(NPY_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 2nd argument `y' of _test_odeint_banded.banded5x5 to C/Fortran array" );
  } else {
    y = (double *)(PyArray_DATA(capi_y_tmp));

  /* Processing variable n */
  if (n_capi == Py_None) n = len(y); else
    f2py_success = int_from_pyobj(&n,n_capi,"_test_odeint_banded.banded5x5() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(y)>=n,"len(y)>=n","1st keyword n","banded5x5:n=%d",n) {
  /* Processing variable f */
  f_Dims[0]=n;
  capi_f_intent |= F2PY_INTENT_IN;
  capi_f_tmp = array_from_pyobj(NPY_DOUBLE,f_Dims,f_Rank,capi_f_intent,f_capi);
  if (capi_f_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 3rd argument `f' of _test_odeint_banded.banded5x5 to C/Fortran array" );
  } else {
    f = (double *)(PyArray_DATA(capi_f_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n,&t,y,f);
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
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_f_tmp!=f_capi) {
    Py_XDECREF(capi_f_tmp); }
  }  /*if (capi_f_tmp == NULL) ... else of f*/
  /* End of cleaning variable f */
  } /*CHECKSCALAR(len(y)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*if (f2py_success) of t*/
  /* End of cleaning variable t */
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
/****************************** end of banded5x5 ******************************/

/******************************* banded5x5_jac *******************************/
static char doc_f2py_rout__test_odeint_banded_banded5x5_jac[] = "\
banded5x5_jac(t,y,ml,mu,jac,[n,nrowpd])\n\nWrapper for ``banded5x5_jac``.\
\n\nParameters\n----------\n"
"t : input float\n"
"y : input rank-1 array('d') with bounds (n)\n"
"ml : input int\n"
"mu : input int\n"
"jac : input rank-2 array('d') with bounds (nrowpd,n)\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(y)\n"
"nrowpd : input int, optional\n    Default: shape(jac,0)";
/* extern void F_FUNC_US(banded5x5_jac,BANDED5X5_JAC)(int*,double*,double*,int*,int*,double*,int*); */
static PyObject *f2py_rout__test_odeint_banded_banded5x5_jac(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,int*,int*,double*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  double t = 0;
  PyObject *t_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[1] = {-1};
  const int y_Rank = 1;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int ml = 0;
  PyObject *ml_capi = Py_None;
  int mu = 0;
  PyObject *mu_capi = Py_None;
  double *jac = NULL;
  npy_intp jac_Dims[2] = {-1, -1};
  const int jac_Rank = 2;
  PyArrayObject *capi_jac_tmp = NULL;
  int capi_jac_intent = 0;
  PyObject *jac_capi = Py_None;
  int nrowpd = 0;
  PyObject *nrowpd_capi = Py_None;
  static char *capi_kwlist[] = {"t","y","ml","mu","jac","n","nrowpd",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OO:_test_odeint_banded.banded5x5_jac",\
    capi_kwlist,&t_capi,&y_capi,&ml_capi,&mu_capi,&jac_capi,&n_capi,&nrowpd_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable ml */
    f2py_success = int_from_pyobj(&ml,ml_capi,"_test_odeint_banded.banded5x5_jac() 3rd argument (ml) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mu */
    f2py_success = int_from_pyobj(&mu,mu_capi,"_test_odeint_banded.banded5x5_jac() 4th argument (mu) can't be converted to int");
  if (f2py_success) {
  /* Processing variable t */
    f2py_success = double_from_pyobj(&t,t_capi,"_test_odeint_banded.banded5x5_jac() 1st argument (t) can't be converted to double");
  if (f2py_success) {
  /* Processing variable y */
  ;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(NPY_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 2nd argument `y' of _test_odeint_banded.banded5x5_jac to C/Fortran array" );
  } else {
    y = (double *)(PyArray_DATA(capi_y_tmp));

  /* Processing variable n */
  if (n_capi == Py_None) n = len(y); else
    f2py_success = int_from_pyobj(&n,n_capi,"_test_odeint_banded.banded5x5_jac() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(y)>=n,"len(y)>=n","1st keyword n","banded5x5_jac:n=%d",n) {
  /* Processing variable jac */
  jac_Dims[1]=n;
  capi_jac_intent |= F2PY_INTENT_IN;
  capi_jac_tmp = array_from_pyobj(NPY_DOUBLE,jac_Dims,jac_Rank,capi_jac_intent,jac_capi);
  if (capi_jac_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 5th argument `jac' of _test_odeint_banded.banded5x5_jac to C/Fortran array" );
  } else {
    jac = (double *)(PyArray_DATA(capi_jac_tmp));

  /* Processing variable nrowpd */
  if (nrowpd_capi == Py_None) nrowpd = shape(jac,0); else
    f2py_success = int_from_pyobj(&nrowpd,nrowpd_capi,"_test_odeint_banded.banded5x5_jac() 2nd keyword (nrowpd) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(jac,0)==nrowpd,"shape(jac,0)==nrowpd","2nd keyword nrowpd","banded5x5_jac:nrowpd=%d",nrowpd) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n,&t,y,&ml,&mu,jac,&nrowpd);
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
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(shape(jac,0)==nrowpd)*/
  } /*if (f2py_success) of nrowpd*/
  /* End of cleaning variable nrowpd */
  if((PyObject *)capi_jac_tmp!=jac_capi) {
    Py_XDECREF(capi_jac_tmp); }
  }  /*if (capi_jac_tmp == NULL) ... else of jac*/
  /* End of cleaning variable jac */
  } /*CHECKSCALAR(len(y)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*if (f2py_success) of t*/
  /* End of cleaning variable t */
  } /*if (f2py_success) of mu*/
  /* End of cleaning variable mu */
  } /*if (f2py_success) of ml*/
  /* End of cleaning variable ml */
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
/**************************** end of banded5x5_jac ****************************/

/******************************* banded5x5_bjac *******************************/
static char doc_f2py_rout__test_odeint_banded_banded5x5_bjac[] = "\
banded5x5_bjac(t,y,ml,mu,bjac,[n,nrowpd])\n\nWrapper for ``banded5x5_bjac``.\
\n\nParameters\n----------\n"
"t : input float\n"
"y : input rank-1 array('d') with bounds (5)\n"
"ml : input int\n"
"mu : input int\n"
"bjac : input rank-2 array('d') with bounds (nrowpd,n)\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: shape(bjac,1)\n"
"nrowpd : input int, optional\n    Default: shape(bjac,0)";
/* extern void F_FUNC_US(banded5x5_bjac,BANDED5X5_BJAC)(int*,double*,double*,int*,int*,double*,int*); */
static PyObject *f2py_rout__test_odeint_banded_banded5x5_bjac(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,int*,int*,double*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  double t = 0;
  PyObject *t_capi = Py_None;
  double *y = NULL;
  npy_intp y_Dims[1] = {-1};
  const int y_Rank = 1;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int ml = 0;
  PyObject *ml_capi = Py_None;
  int mu = 0;
  PyObject *mu_capi = Py_None;
  double *bjac = NULL;
  npy_intp bjac_Dims[2] = {-1, -1};
  const int bjac_Rank = 2;
  PyArrayObject *capi_bjac_tmp = NULL;
  int capi_bjac_intent = 0;
  PyObject *bjac_capi = Py_None;
  int nrowpd = 0;
  PyObject *nrowpd_capi = Py_None;
  static char *capi_kwlist[] = {"t","y","ml","mu","bjac","n","nrowpd",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OO:_test_odeint_banded.banded5x5_bjac",\
    capi_kwlist,&t_capi,&y_capi,&ml_capi,&mu_capi,&bjac_capi,&n_capi,&nrowpd_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable ml */
    f2py_success = int_from_pyobj(&ml,ml_capi,"_test_odeint_banded.banded5x5_bjac() 3rd argument (ml) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mu */
    f2py_success = int_from_pyobj(&mu,mu_capi,"_test_odeint_banded.banded5x5_bjac() 4th argument (mu) can't be converted to int");
  if (f2py_success) {
  /* Processing variable t */
    f2py_success = double_from_pyobj(&t,t_capi,"_test_odeint_banded.banded5x5_bjac() 1st argument (t) can't be converted to double");
  if (f2py_success) {
  /* Processing variable y */
  y_Dims[0]=5;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(NPY_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 2nd argument `y' of _test_odeint_banded.banded5x5_bjac to C/Fortran array" );
  } else {
    y = (double *)(PyArray_DATA(capi_y_tmp));

  /* Processing variable bjac */
  ;
  capi_bjac_intent |= F2PY_INTENT_IN;
  capi_bjac_tmp = array_from_pyobj(NPY_DOUBLE,bjac_Dims,bjac_Rank,capi_bjac_intent,bjac_capi);
  if (capi_bjac_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 5th argument `bjac' of _test_odeint_banded.banded5x5_bjac to C/Fortran array" );
  } else {
    bjac = (double *)(PyArray_DATA(capi_bjac_tmp));

  /* Processing variable n */
  if (n_capi == Py_None) n = shape(bjac,1); else
    f2py_success = int_from_pyobj(&n,n_capi,"_test_odeint_banded.banded5x5_bjac() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(bjac,1)==n,"shape(bjac,1)==n","1st keyword n","banded5x5_bjac:n=%d",n) {
  /* Processing variable nrowpd */
  if (nrowpd_capi == Py_None) nrowpd = shape(bjac,0); else
    f2py_success = int_from_pyobj(&nrowpd,nrowpd_capi,"_test_odeint_banded.banded5x5_bjac() 2nd keyword (nrowpd) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(bjac,0)==nrowpd,"shape(bjac,0)==nrowpd","2nd keyword nrowpd","banded5x5_bjac:nrowpd=%d",nrowpd) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n,&t,y,&ml,&mu,bjac,&nrowpd);
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
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(shape(bjac,0)==nrowpd)*/
  } /*if (f2py_success) of nrowpd*/
  /* End of cleaning variable nrowpd */
  } /*CHECKSCALAR(shape(bjac,1)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  if((PyObject *)capi_bjac_tmp!=bjac_capi) {
    Py_XDECREF(capi_bjac_tmp); }
  }  /*if (capi_bjac_tmp == NULL) ... else of bjac*/
  /* End of cleaning variable bjac */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*if (f2py_success) of t*/
  /* End of cleaning variable t */
  } /*if (f2py_success) of mu*/
  /* End of cleaning variable mu */
  } /*if (f2py_success) of ml*/
  /* End of cleaning variable ml */
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
/*************************** end of banded5x5_bjac ***************************/

/****************************** banded5x5_solve ******************************/
static char doc_f2py_rout__test_odeint_banded_banded5x5_solve[] = "\
nst,nfe,nje = banded5x5_solve(y,nsteps,dt,jt)\n\nWrapper for ``banded5x5_solve``.\
\n\nParameters\n----------\n"
"y : in/output rank-1 array('d') with bounds (5)\n"
"nsteps : input int\n"
"dt : input float\n"
"jt : input int\n"
"\nReturns\n-------\n"
"nst : int\n"
"nfe : int\n"
"nje : int";
/* extern void F_FUNC_US(banded5x5_solve,BANDED5X5_SOLVE)(double*,int*,double*,int*,int*,int*,int*); */
static PyObject *f2py_rout__test_odeint_banded_banded5x5_solve(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,int*,double*,int*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *y = NULL;
  npy_intp y_Dims[1] = {-1};
  const int y_Rank = 1;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  int nsteps = 0;
  PyObject *nsteps_capi = Py_None;
  double dt = 0;
  PyObject *dt_capi = Py_None;
  int jt = 0;
  PyObject *jt_capi = Py_None;
  int nst = 0;
  int nfe = 0;
  int nje = 0;
  static char *capi_kwlist[] = {"y","nsteps","dt","jt",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO:_test_odeint_banded.banded5x5_solve",\
    capi_kwlist,&y_capi,&nsteps_capi,&dt_capi,&jt_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable y */
  y_Dims[0]=5;
  capi_y_intent |= F2PY_INTENT_INOUT;
  capi_y_tmp = array_from_pyobj(NPY_DOUBLE,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_test_odeint_banded_error,"failed in converting 1st argument `y' of _test_odeint_banded.banded5x5_solve to C/Fortran array" );
  } else {
    y = (double *)(PyArray_DATA(capi_y_tmp));

  /* Processing variable dt */
    f2py_success = double_from_pyobj(&dt,dt_capi,"_test_odeint_banded.banded5x5_solve() 3rd argument (dt) can't be converted to double");
  if (f2py_success) {
  /* Processing variable nsteps */
    f2py_success = int_from_pyobj(&nsteps,nsteps_capi,"_test_odeint_banded.banded5x5_solve() 2nd argument (nsteps) can't be converted to int");
  if (f2py_success) {
  /* Processing variable jt */
    f2py_success = int_from_pyobj(&jt,jt_capi,"_test_odeint_banded.banded5x5_solve() 4th argument (jt) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nst */
  /* Processing variable nfe */
  /* Processing variable nje */
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(y,&nsteps,&dt,&jt,&nst,&nfe,&nje);
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
    capi_buildvalue = Py_BuildValue("iii",nst,nfe,nje);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  /* End of cleaning variable nje */
  /* End of cleaning variable nfe */
  /* End of cleaning variable nst */
  } /*if (f2py_success) of jt*/
  /* End of cleaning variable jt */
  } /*if (f2py_success) of nsteps*/
  /* End of cleaning variable nsteps */
  } /*if (f2py_success) of dt*/
  /* End of cleaning variable dt */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
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
/*************************** end of banded5x5_solve ***************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_jac_def[] = {
  {"bands",2,{{4,5}},NPY_DOUBLE},
  {NULL}
};
static void f2py_setup_jac(char *bands) {
  int i_f2py=0;
  f2py_jac_def[i_f2py++].data = bands;
}
extern void F_FUNC(f2pyinitjac,F2PYINITJAC)(void(*)(char*));
static void f2py_init_jac(void) {
  F_FUNC(f2pyinitjac,F2PYINITJAC)(f2py_setup_jac);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"getbands",-1,{{-1}},0,(char *)F_FUNC(getbands,GETBANDS),(f2py_init_func)f2py_rout__test_odeint_banded_getbands,doc_f2py_rout__test_odeint_banded_getbands},
  {"banded5x5",-1,{{-1}},0,(char *)F_FUNC(banded5x5,BANDED5X5),(f2py_init_func)f2py_rout__test_odeint_banded_banded5x5,doc_f2py_rout__test_odeint_banded_banded5x5},
  {"banded5x5_jac",-1,{{-1}},0,(char *)F_FUNC_US(banded5x5_jac,BANDED5X5_JAC),(f2py_init_func)f2py_rout__test_odeint_banded_banded5x5_jac,doc_f2py_rout__test_odeint_banded_banded5x5_jac},
  {"banded5x5_bjac",-1,{{-1}},0,(char *)F_FUNC_US(banded5x5_bjac,BANDED5X5_BJAC),(f2py_init_func)f2py_rout__test_odeint_banded_banded5x5_bjac,doc_f2py_rout__test_odeint_banded_banded5x5_bjac},
  {"banded5x5_solve",-1,{{-1}},0,(char *)F_FUNC_US(banded5x5_solve,BANDED5X5_SOLVE),(f2py_init_func)f2py_rout__test_odeint_banded_banded5x5_solve,doc_f2py_rout__test_odeint_banded_banded5x5_solve},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_test_odeint_banded",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit__test_odeint_banded(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_test_odeint_banded(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _test_odeint_banded_module = PyModule_Create(&moduledef);
#else
  m = _test_odeint_banded_module = Py_InitModule("_test_odeint_banded", f2py_module_methods);
#endif
  Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _test_odeint_banded (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_test_odeint_banded' is auto-generated with f2py (version:2).\nFunctions:\n"
"  jac = getbands()\n"
"  banded5x5(t,y,f,n=len(y))\n"
"  banded5x5_jac(t,y,ml,mu,jac,n=len(y),nrowpd=shape(jac,0))\n"
"  banded5x5_bjac(t,y,ml,mu,bjac,n=shape(bjac,1),nrowpd=shape(bjac,0))\n"
"  nst,nfe,nje = banded5x5_solve(y,nsteps,dt,jt)\n"
"COMMON blocks:\n""  /jac/ bands(4,5)\n"".");
  PyDict_SetItemString(d, "__doc__", s);
  _test_odeint_banded_error = PyErr_NewException ("_test_odeint_banded.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));





/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

  F2PyDict_SetItemString(d, "jac", PyFortranObject_New(f2py_jac_def,f2py_init_jac));
/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_test_odeint_banded");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
