#include <stdarg.h>
#include <stdio.h>

#include "cypdf_utils.h"
#include "cypdf_consts.h"
#include "cypdf_types.h"



void CYPDF_StrToBytes(const char* src, CYPDF_BYTE* dest, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        dest[i] = (CYPDF_BYTE)src[i];
    }
}
