#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_header.h"
#include "cypdf_print.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"
#include "cypdf_version.h"


CYPDF_File_Header* CYPDF_New_File_Header() {
    CYPDF_File_Header* file_header = CYPDF_smalloc(sizeof(CYPDF_File_Header));
    if (file_header) {
        file_header->version_size = strlen(CYPDF_PDF_VERSION) + 1;
        file_header->version = CYPDF_scalloc(1, file_header->version_size);
        if (file_header->version) {
            strcpy(file_header->version, CYPDF_PDF_VERSION);
        } else {
            file_header->version_size = 0;
        }
        
        file_header->hival_bytes_size = strlen(CYPDF_HIVAL_BYTES) + 1;
        file_header->hival_bytes = CYPDF_scalloc(1, file_header->hival_bytes_size);
        if (file_header->hival_bytes) {
            strcpy(file_header->hival_bytes, CYPDF_HIVAL_BYTES);
        } else {
            file_header->hival_bytes_size = 0;
        }
    }

    return file_header;
}

void CYPDF_Write_File_Header(FILE* fp, CYPDF_File_Header* file_header) {
    CYPDF_Write_Comment(fp, file_header->version);
    CYPDF_Write_Comment(fp, file_header->hival_bytes);
}

void CYPDF_Free_File_Header(CYPDF_File_Header* file_header) {
    if (file_header) {
        free(file_header->version);
        free(file_header->hival_bytes);
        free(file_header);
    }
}
