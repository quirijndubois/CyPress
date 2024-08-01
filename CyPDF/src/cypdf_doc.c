#include <stdio.h>
#include <stdlib.h>

#include "cypdf_doc.h"
#include "cypdf_catalog.h"
#include "cypdf_header.h"
#include "cypdf_utils.h"



CYPDF_Doc* CYPDF_Doc_New() {
    CYPDF_Doc* pdf_doc = CYPDF_safe_malloc(sizeof(CYPDF_Doc));
    if (pdf_doc != NULL) {
        pdf_doc->file_header = CYPDF_File_Header_New();
    }

    return pdf_doc;
}

void CYPDF_Doc_Write(FILE* fp, CYPDF_Doc* pdf_doc) {
    if (fp == NULL || pdf_doc == NULL) {
        return;
    }

    CYPDF_File_Header_Write(fp, pdf_doc->file_header);
}

void CYPDF_Doc_Free(CYPDF_Doc* pdf_doc) {
    if (pdf_doc == NULL) {
        return;
    }

    CYPDF_File_Header_Free(pdf_doc->file_header);
    free(pdf_doc);
}