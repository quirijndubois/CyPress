#include <stdio.h>
#include <stdlib.h>

#include "cypdf_doc.h"
#include "cypdf_catalog.h"
#include "cypdf_header.h"



CYPDF_Doc* CYPDF_Doc_New() {
    CYPDF_Doc* pdf_doc = malloc(sizeof(CYPDF_Doc));
    if (!pdf_doc) {
        printf("Error: Failed to allocate memory for pdf document.\n");
    } else {
        CYPDF_File_Header* file_header = CYPDF_File_Header_New();
        pdf_doc->file_header = file_header;
    }

    return pdf_doc;
}

void CYPDF_Doc_Write(FILE* fp, CYPDF_Doc* pdf_doc) {
    if (!fp) {
        printf("Error: No valid file pointer was passed to CYPDF_Doc_Write.\n");
        return;
    } else if (!pdf_doc) {
        printf("Error: No valid pdf document was passed to CYPDF_Doc_Write.\n");
    }

    CYPDF_File_Header_Write(fp, pdf_doc->file_header);

}

void CYPDF_Doc_Free(CYPDF_Doc* pdf_doc) {
    if (pdf_doc) {
        CYPDF_File_Header_Free(pdf_doc->file_header);
    }
    free(pdf_doc);
}