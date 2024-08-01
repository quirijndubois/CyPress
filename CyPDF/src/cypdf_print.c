#include <stdio.h>

#include "cypdf_print.h"
#include "cypdf_consts.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



void CYPDF_fwrite_LF(const void* buffer, size_t element_size, size_t element_count, FILE* stream) {
    if (buffer == NULL || stream == NULL) {
        return;
    }

    fwrite(buffer, element_size, element_count, stream);
    fprintf(stream, "%s", CYPDF_NEW_LINE);
}

void CYPDF_Write_Comment(FILE* fp, CYPDF_BYTE* src, size_t size) {
    if (fp == NULL || src == NULL) {
        return;
    }
    
    fputc('%', fp);
    CYPDF_fwrite_LF(src, sizeof(src[0]), size, fp);
}
