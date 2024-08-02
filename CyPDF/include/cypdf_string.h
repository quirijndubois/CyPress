#ifndef CYPDF_STRING_H
#define CYPDF_STRING_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_STRING          CYPDF_Write_String
#define CYPDF_FREE_STRING           CYPDF_Free_String


typedef struct _CYPDF_String_obj {
    CYPDF_Obj_Header        header;
    CYPDF_BYTE*             value;
    CYPDF_SIZE              size;
} CYPDF_Obj_String;


/**
 * @brief Creates new CYPDF_Obj_String initialized with value. If memory allocation for obj->value fails, obj->value is set to NULL and obj->size is set to 0.
 * 
 * @param indirect 
 * @param ID 
 * @param value 
 * @param valsize Size of value in bytes.
 * @return CYPDF_Obj_String* | Returns NULL if object creation fails.
 */
CYPDF_Obj_String* CPYDF_New_String(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_BYTE* value, CYPDF_SIZE valsize);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_String(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_String(CYPDF_Object* obj);



#endif /* CYPDF_STRING_H */