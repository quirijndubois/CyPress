#ifndef CYPDF_CATALOG_H
#define CYPDF_CATALOG_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_CATALOG_OBJ_WRITE         CYPDF_Catalog_Obj_Write
#define CYPDF_CATALOG_OBJ_FREE          CYPDF_Catalog_Obj_Free


/* CYPDF_Catalog_Obj struct */
typedef struct _CYPDF_Catalog_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_Dict_Obj*         dict;
} CYPDF_Catalog_Obj;


/**
 * @brief Creates new CYPDF_Catalog_Obj.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @return CYPDF_Catalog_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Catalog_Obj* CYPDF_Catalog_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Catalog_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Catalog_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_CATALOG_H */