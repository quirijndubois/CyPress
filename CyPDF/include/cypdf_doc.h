#ifndef CYPDF_DOC_H
#define CYPDF_DOC_H


#include <stdio.h>

#include "cypdf_catalog.h"
#include "cypdf_header.h"
#include "cypdf_list.h"
#include "cypdf_pages.h"
#include "cypdf_types.h"



/* CYPDF_doc struct */
typedef struct _CYPDF_Doc {
    CYPDF_File_Header*      file_header;
    CYPDF_Obj_Catalog*      catalog;
    CYPDF_Obj_PNode*        page_tree;
    
    CYPDF_Obj_List*         obj_list;
    CYPDF_UINT32            curr_ID;
} CYPDF_Doc;


/**
 * @brief Creates new CYPDF_Doc.
 * 
 * @return CYPDF_Doc* | Returns NULL if memory allocation fails.
 */
CYPDF_Doc* CYPDF_New_Doc();

/**
 * @brief Append a new page to pdf_doc.
 * 
 * @param pdf_doc 
 */
void CYPDF_Append_Page(CYPDF_Doc* pdf_doc);

/**
 * @brief Writes pdf_doc to fp. Does nothing if fp == NULL or pdf_doc == NULL.
 * 
 * @param fp 
 * @param pdf_doc 
 */
void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf_doc);

/**
 * @brief Frees pdf_doc. Does nothing if pdf_doc is NULL.
 * 
 * @param pdf_doc 
 */
void CYPDF_Free_Doc(CYPDF_Doc* pdf_doc);



#endif /* CYPDF_DOC_H */