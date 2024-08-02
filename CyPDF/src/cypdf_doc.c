#include <stdio.h>
#include <stdlib.h>

#include "cypdf_doc.h"
#include "cypdf_catalog.h"
#include "cypdf_header.h"
#include "cypdf_utils.h"



CYPDF_Doc* CYPDF_New_Doc() {
    CYPDF_Doc* pdf_doc = CYPDF_smalloc(sizeof(CYPDF_Doc));
    if (pdf_doc != NULL) {
        pdf_doc->file_header = CYPDF_New_File_Header();
    }

    return pdf_doc;
}

void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf_doc) {
    if (fp == NULL || pdf_doc == NULL) {
        return;
    }

    CYPDF_Write_File_Header(fp, pdf_doc->file_header);
}

void CYPDF_Free_Doc(CYPDF_Doc* pdf_doc) {
    if (pdf_doc == NULL) {
        return;
    }

    CYPDF_Free_File_Header(pdf_doc->file_header);
    free(pdf_doc);
}