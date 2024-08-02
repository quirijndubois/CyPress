#ifndef CYPDF_ARRAY_H
#define CYPDF_ARRAY_H


#include <stdio.h>

#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_ARRAY               CYPDF_Write_Array
#define CYPDF_FREE_ARRAY                CYPDF_Free_Array


/* CYPDF_Obj_Array struct */
typedef struct _CYPDF_Obj_Array {
    CYPDF_Obj_Header        header;
    CYPDF_List*             obj_list;
} CYPDF_Obj_Array;


/**
 * @brief Creates new CYPDF_Obj_Array. The obj_list gets initialized with free_func.
 * 
 * @param indirect 
 * @param ID 
 * @param free_func Free function pointer belonging to the type of the obj->obj_list elements.
 * @return CYPDF_Obj_Array* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Array* CYPDF_New_Array(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Free_Func free_func);

/**
 * @brief Creates new CYPDF_Obj_Array from a CYPDF_Rect.
 * 
 * @param rect 
 * @param indirect 
 * @param ID 
 * @return CYPDF_Obj_Array* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Array* CYPDF_Array_From_Rect(CYPDF_Rect rect, CYPDF_BOOL indirect, CYPDF_UINT32 ID);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Array(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Array(CYPDF_Object* obj);



#endif /* CYPDF_ARRAY_H */