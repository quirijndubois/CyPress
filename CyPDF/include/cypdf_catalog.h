#ifndef CYPDF_CATALOG_H
#define CYPDF_CATALOG_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_pages.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_CATALOG             CYPDF_Write_Catalog
#define CYPDF_FREE_CATALOG              CYPDF_Free_Catalog


/* CYPDF_Obj_Catalog struct */
typedef struct _CYPDF_Obj_Catalog {
    CYPDF_Obj_Header        header;
    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_Catalog;


/**
 * @brief Creates new CYPDF_Obj_Catalog.
 * 
 * @param indirect 
 * @param ID 
 * @return CYPDF_Obj_Catalog* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Catalog* CYPDF_New_Catalog(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* pages);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Catalog(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Catalog(CYPDF_Object* obj);



#endif /* CYPDF_CATALOG_H */