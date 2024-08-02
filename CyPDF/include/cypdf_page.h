#ifndef CYPDF_PAGE_H
#define CYPDF_PAGE_H


#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_pages.h"



#define CYPDF_WRITE_PAGE                CYPDF_Write_Page
#define CYPDF_FREE_PAGE                 CYPDF_Free_Page


/* CYPDF_Obj_Page struct */
typedef struct _CYPDF_Obj_Page {
    CYPDF_Obj_Header        header;
    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_Page;


/**
 * @brief Creates new CYPDF_Obj_Page.
 * 
 * @param indirect 
 * @param ID 
 * @param parent 
 * @param mediabox 
 * @return CYPDF_Obj_Page* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Page* CYPDF_New_Page(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_Pages* parent, CYPDF_Rect mediabox);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Page(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Page(CYPDF_Object* obj);



#endif /* CYPDF_PAGE_H */