#ifndef CYPDF_PRINT_H
#define CYPDF_PRINT_H


#include <stdio.h>

#include "cypdf_types.h"



void CYPDF_fwrite_nl(const void* buffer, size_t element_size, size_t element_count, FILE* stream);

void CYPDF_Write_Comment(FILE* fp, CYPDF_BYTE* src, size_t size);



#endif /* CYPDF_PRINT_H */