#ifndef CYPDF_NUMBER_H
#define CYPDF_NUMBER_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_NUMBER              CYPDF_Write_Number
#define CYDPF_FREE_NUMBER               CYPDF_Free_Number


/* CYPDF_Obj_Number struct */
typedef struct _CYPDF_Obj_Number {
    CYPDF_Obj_Header        header;
    CYPDF_INT               value;
} CYPDF_Obj_Number;


/**
 * @brief Creates new CYPDF_Obj_Number initialized with value.
 * 
 * @param indirect 
 * @param ID 
 * @param value 
 * @return CYPDF_Obj_Number* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Number* CYPDF_New_Number(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_INT value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Number(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Number(CYPDF_Object* obj);



#endif /* CYPDF_NUMBER_H */
