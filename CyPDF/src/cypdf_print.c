#include <stdio.h>
#include <stdlib.h>

#include "cypdf_print.h"
#include "cypdf_consts.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



void CYPDF_fwrite_LF(const void* buffer, size_t element_size, size_t element_count, FILE* stream) {
    fwrite(buffer, element_size, element_count, stream);
    CYPDF_BYTE* new_line = malloc(sizeof(CYPDF_NEW_LINE) - 1);
    CYPDF_StrToBytes(CYPDF_NEW_LINE, new_line, sizeof(CYPDF_NEW_LINE) - 1);
    fwrite(new_line, sizeof(new_line[0]), sizeof(CYPDF_NEW_LINE) - 1, stream);
}

void CYPDF_Write_Comment(FILE* fp, CYPDF_BYTE* src, size_t size) {
    if (!fp) {
        printf("Error: Passed invalid file pointer to CYPDF_Write_Comment.\n");
    } else if (!src) {
        printf("Error: Passed invalid src pointer to CYPDF_Write_Comment.\n");
    }
    fputc('%', fp);
    CYPDF_fwrite_nl(src, sizeof(src[0]), size, fp);
}
