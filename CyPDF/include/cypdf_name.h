#ifndef CYPDF_NAME_H
#define CYPDF_NAME_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_NAME_OBJ_WRITE            CYPDF_Name_Obj_Write
#define CYPDF_NAME_OBJ_FREE             CYPDF_Name_Obj_Free


#define CYPDF_MAX_NAME_LEN              127


/* CYPDF_Name_Obj struct */
typedef struct _CYPDF_Name_Obj {
    CYPDF_Obj_Header*       header;
    char                    value[CYPDF_MAX_NAME_LEN + 1];
} CYPDF_Name_Obj;


/**
 * @brief Creates new CYPDF_Name_Obj initialized with value. If the length of value exceeds CYPDF_MAX_NAME_LEN, only the first CYPDF_MAX_NAME_LEN characters of value are used to initialize the CYPDF_Name_Obj.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @param value 
 * @return CYPDF_Name_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Name_Obj* CYPDF_Name_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, const char* value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Name_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Name_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NAME_H */