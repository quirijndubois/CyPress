#ifndef CYPDF_REAL_H
#define CYPDF_REAL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_REAL                CYPDF_Write_Real
#define CYPDF_FREE_REAL                 CYPDF_Free_Real


/* CYPDF_Obj_Real struct */
typedef struct _CYPDF_Obj_Real {
    CYPDF_Obj_Header        header;
    CYPDF_REAL              value;
} CYPDF_Obj_Real;


/**
 * @brief Creates new CYPDF_Obj_Real initialized with value.
 * 
 * @param indirect 
 * @param ID 
 * @param value 
 * @return CYPDF_Obj_Real* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Real* CYPDF_New_Real(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_REAL value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Real(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Real(CYPDF_Object* obj);



#endif /* CYPDF_REAL_H */
