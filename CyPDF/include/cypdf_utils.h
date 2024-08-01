#ifndef CYPDF_UTILS_H
#define CYPDF_UTILS_H


#include <ctype.h>

#include "cypdf_types.h"



#define MAX(a, b) ((a) > (b) ? (a) : (b))


void CYPDF_StrToBytes(const char* src, CYPDF_BYTE* dest, size_t size);

void* CYPDF_safe_malloc(size_t size);

void* CYPDF_safe_calloc(size_t element_count, size_t element_size);



#endif /* CYPDF_UTILS_H */