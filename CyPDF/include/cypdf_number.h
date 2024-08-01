#ifndef CYPDF_NUMBER_H
#define CYPDF_NUMBER_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_NUMBER_OBJ_WRITE          CYPDF_Number_Obj_Write
#define CYDPF_NUMBER_OBJ_FREE           CYPDF_Number_Obj_Free


/* CYPDF_Number_Obj struct */
typedef struct _CYPDF_Number_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_INT               value;
} CYPDF_Number_Obj;


/**
 * @brief Creates new CYPDF_Number_Obj initialized with value.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @param value 
 * @return CYPDF_Number_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Number_Obj* CYPDF_Number_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_INT value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Number_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Number_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NUMBER_H */