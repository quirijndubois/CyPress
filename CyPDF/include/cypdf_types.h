#ifndef CYPDF_TYPES_H
#define CYPDF_TYPES_H


#include <stdio.h>



/* native OS integer types */
typedef signed int          CYPDF_INT;
typedef unsigned int        CYPDF_UINT;


/* 64bit integer types */
typedef signed long long    CYPDF_INT64;
typedef unsigned long long  CYPDF_UINT64;


/* 32bit integer types */
typedef signed int          CYPDF_INT32;
typedef unsigned int        CYPDF_UINT32;


/* 16bit integer types */
typedef signed short        CYPDF_INT16;
typedef unsigned short      CYPDF_UINT16;


/* 8bit integer types */
typedef signed char         CYPDF_INT8;
typedef unsigned char       CYPDF_UINT8;


/* 8bit binary types */
typedef unsigned char       CYPDF_BYTE;


/* float type (32bit IEEE754) */
typedef float               CYPDF_REAL;


/* double type (64bit IEEE754) */
typedef double              CYPDF_DOUBLE;


/* boolean type (0: False, !0: True) */
typedef signed int          CYPDF_BOOL;


/* size type */
typedef size_t              CYPDF_SIZE;


/* CYPDF_Point struct */
typedef struct _CYPDF_Point {
    CYPDF_REAL x;
    CYPDF_REAL y;
} CYPDF_POINT;


/* CYPDF_Rect struct */
typedef struct _CYPDF_Rect {
    CYPDF_REAL lowleftx;
    CYPDF_REAL lowlefty;
    CYPDF_REAL uprightx;
    CYPDF_REAL uprighty;
} CYPDF_Rect;


typedef void CYPDF_Object;


/* CYPDF function types */
typedef void (*CYPDF_Free_Func)(CYPDF_Object*);
typedef void (*CYPDF_Write_Func)(FILE*, CYPDF_Object*);



#endif