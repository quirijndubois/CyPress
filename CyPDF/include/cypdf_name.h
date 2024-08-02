#ifndef CYPDF_NAME_H
#define CYPDF_NAME_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_TYPE_NAME                 "Type"


#define CYPDF_WRITE_NAME                CYPDF_Write_Name
#define CYPDF_FREE_NAME                 CYPDF_Free_Name


#define CYPDF_MAX_NAME_LEN              127


/* CYPDF_Obj_Name struct */
typedef struct _CYPDF_Obj_Name {
    CYPDF_Obj_Header        header;
    char                    value[CYPDF_MAX_NAME_LEN + 1];
} CYPDF_Obj_Name;


/**
 * @brief Creates new CYPDF_Obj_Name initialized with value. If the length of value exceeds CYPDF_MAX_NAME_LEN, only the first CYPDF_MAX_NAME_LEN characters of value are used to initialize the CYPDF_Obj_Name.
 * 
 * @param indirect 
 * @param ID 
 * @param value 
 * @return CYPDF_Obj_Name* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Name* CYPDF_New_Name(CYPDF_BOOL indirect, CYPDF_UINT32 ID, const char* value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Name(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Name(CYPDF_Object* obj);



#endif /* CYPDF_NAME_H */