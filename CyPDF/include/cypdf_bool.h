#ifndef CYPDF_BOOL_H
#define CYPDF_BOOL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_BOOL_OBJ_WRITE            CYPDF_Bool_Obj_Write
#define CYPDF_BOOL_OBJ_FREE             CYPDF_Bool_Obj_Free


/* CYPDF_Bool_Obj struct */
typedef struct _CYPDF_Bool_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_BOOL              value;
} CYPDF_Bool_Obj;


/**
 * @brief Creates new CYPDF_Bool_Obj initialized with value.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @param value 
 * @return CYPDF_Bool_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Bool_Obj* CYPDF_Bool_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BOOL value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Bool_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Bool_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_BOOL_H */