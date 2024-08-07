#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "cypdf_print.h"
#include "cypdf_consts.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



size_t CYPDF_fwrite_NL(const void* buffer, size_t element_size, size_t element_count, FILE* stream) {
    size_t ret = fwrite(buffer, element_size, element_count, stream) * element_size;
    ret += CYPDF_Write_NL(stream);

    return ret;
}

size_t CYPDF_Write_NL(FILE* stream) {
    return fwrite(CYPDF_NEW_LINE, sizeof(char), strlen(CYPDF_NEW_LINE), stream) * sizeof(char);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
int CYPDF_fprintf_NL(FILE* stream, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vfprintf(stream, format, args);
    va_end(args);

    ret += (int)CYPDF_Write_NL(stream);

    return ret;
}
#pragma GCC diagnostic pop

size_t CYPDF_Write_Comment(FILE* fp, const char* src) {
    size_t ret = 0;

    if (fputc('%', fp) != EOF) {
        ret = 1;
    }
    ret += CYPDF_fwrite_NL(src, sizeof(src[0]), strlen(src), fp);

    return ret;
}
