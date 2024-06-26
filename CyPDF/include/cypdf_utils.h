#ifndef CYPDF_UTILS_H
#define CYPDF_UTILS_H


#include "cypdf_types.h"



#define MAX(a, b) ((a) > (b) ? (a) : (b))


void CYPDF_StrToBytes(const char* src, CYPDF_BYTE* dest, size_t size);



#endif /* CYPDF_UTILS_H */