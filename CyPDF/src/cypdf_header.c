#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_header.h"
#include "cypdf_print.h"
#include "cypdf_utils.h"
#include "cypdf_version.h"


CYPDF_File_Header* CYPDF_New_File_Header() {
    CYPDF_File_Header* file_header = CYPDF_smalloc(sizeof(CYPDF_File_Header));
    if (file_header) {
        file_header->version = CYPDF_smalloc(sizeof(CYPDF_PDF_VERSION) - 1);
        if (file_header->version != NULL) {
            file_header->version_size = sizeof(CYPDF_PDF_VERSION) - 1;
            CYPDF_StrToBytes(CYPDF_PDF_VERSION, file_header->version, file_header->version_size);
        }
        
        file_header->hival_bytes = CYPDF_smalloc(sizeof(CYPDF_HIVAL_BYTES) - 1);
        if (file_header->hival_bytes != NULL) {
            file_header->hival_bytes_size = sizeof(CYPDF_HIVAL_BYTES) - 1;
            CYPDF_StrToBytes(CYPDF_HIVAL_BYTES, file_header->hival_bytes, file_header->hival_bytes_size);
        }
    }

    return file_header;
}

void CYPDF_Write_File_Header(FILE* fp, CYPDF_File_Header* file_header) {
    if (fp == NULL || file_header == NULL) {
        return;
    }

    CYPDF_Write_Comment(fp, file_header->version, file_header->version_size);
    CYPDF_Write_Comment(fp, file_header->hival_bytes, file_header->hival_bytes_size);
}

void CYPDF_Free_File_Header(CYPDF_File_Header* file_header) {
    if (file_header == NULL) {
        return;
    }

    free(file_header->version);
    free(file_header->hival_bytes);
    free(file_header);
}
