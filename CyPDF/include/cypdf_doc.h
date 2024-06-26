#ifndef CYPDF_DOC_H
#define CYPDF_DOC_H


#include <stdio.h>

#include "cypdf_catalog.h"
#include "cypdf_header.h"
#include "cypdf_types.h"



/* CYPDF_doc struct */
typedef struct _CYPDF_Doc {
    CYPDF_File_Header*      file_header;
    CYPDF_Catalog_Obj*      catalog;
    
    CYPDF_UINT32            obj_count;
} CYPDF_Doc;


CYPDF_Doc* CYPDF_Doc_New();

void CYPDF_Doc_Write(FILE* fp, CYPDF_Doc* pdf_doc);

void CYPDF_Doc_Free(CYPDF_Doc* pdf_doc);



#endif /* CYPDF_DOC_H */