#ifndef CYPDF_ARRAY_H
#define CYPDF_ARRAY_H


#include <stdio.h>

#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_ARRAY_OBJ_WRITE           CYPDF_Array_Obj_Write
#define CYPDF_ARRAY_OBJ_FREE            CYPDF_Array_Obj_Free


/* CYPDF_Array_Obj struct */
typedef struct _CYPDF_Array_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_List*             obj_list;
} CYPDF_Array_Obj;


/**
 * @brief Creates new CYPDF_Array_Obj. The obj_list gets initialized with free_func.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @param free_func Free function pointer belonging to the type of the obj->obj_list elements.
 * @return CYPDF_Array_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Array_Obj* CYPDF_Array_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_Free_Func free_func);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Array_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Array_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_ARRAY_H */