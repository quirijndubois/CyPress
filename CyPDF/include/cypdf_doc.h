#ifndef CYPDF_DOC_H
#define CYPDF_DOC_H


#include <stdio.h>

#include "cypdf_catalog.h"
#include "cypdf_header.h"
#include "cypdf_info.h"
#include "cypdf_list.h"
#include "cypdf_pages.h"
#include "cypdf_types.h"



/* CYPDF_doc struct */
typedef struct _CYPDF_Doc {
    CYPDF_File_Header*      file_header;

    CYPDF_Obj_Catalog*      catalog;
    CYPDF_Obj_PNode*        page_tree;
    CYPDF_Obj_Info*         info;
    
    CYPDF_Obj_List*         obj_list;
    CYPDF_UINT32            curr_ID;

    CYPDF_INT64*            offsets; /* Byte offsets of the objects in obj_list. */
} CYPDF_Doc;


/**
 * @brief Creates new CYPDF_Doc.
 * 
 * @return CYPDF_Doc* | Returns NULL if memory allocation fails.
 */
CYPDF_Doc* CYPDF_New_Doc();

/**
 * @brief Append a new page to pdf.
 * 
 * @param pdf 
 */
void CYPDF_Append_Page(CYPDF_Doc* pdf);

/**
 * @brief Writes pdf to fp. Does nothing if fp == NULL or pdf == NULL.
 * 
 * @param fp 
 * @param pdf 
 */
void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf, const char* file_path);

/**
 * @brief Frees pdf. Does nothing if pdf is NULL.
 * 
 * @param pdf 
 */
void CYPDF_Free_Doc(CYPDF_Doc* pdf);



#endif /* CYPDF_DOC_H */
