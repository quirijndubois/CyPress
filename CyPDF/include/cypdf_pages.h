#ifndef CYPDF_PAGES_H
#define CYPDF_PAGES_H


#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_PAGES                   CYPDF_Write_Pages
#define CYPDF_FREE_PAGES                    CYPDF_Free_Pages


/* CYPDF_Obj_Pages struct */
typedef struct _CYPDF_Obj_Pages {
    CYPDF_Obj_Header        header;
    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_Pages;


/**
 * @brief Creates new CYPDF_Obj_Pages.
 * 
 * @param indirect 
 * @param ID 
 * @param parent 
 * @return CYPDF_Obj_Pages* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Pages* CYPDF_New_Pages(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_Pages* parent);

/**
 * @brief Write obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Pages(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Pages(CYPDF_Object* obj);



#endif /* CYPDF_PAGES_H */