#include <stdio.h>
#include <stdlib.h>

#include "cypdf_utils.h"
#include "cypdf_types.h"



void CYPDF_StrToBytes(const char* src, CYPDF_BYTE* dest, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        dest[i] = (CYPDF_BYTE)src[i];
    }
}

void* CYPDF_safe_malloc(size_t size) {
    void* mem = malloc(size);
    if (!mem) {
        fprintf(stderr, "Failed to allocate %zu bytes of memory.\n", size);
    }

    return mem;
}

void* CYPDF_safe_calloc(size_t element_count, size_t element_size) {
    void* mem = calloc(element_count, element_size);
    if (!mem) {
        fprintf(stderr, "Failed to allocate %zu bytes of memory.\n", element_count * element_size);
    }

    return mem;
}

void* CYPDF_safe_realloc(void* ptr, size_t size) {
    void* mem = realloc(ptr, size);
    if (mem == NULL) {
        fprintf(stderr, "Failed to reallocate %p to a size of %zu.\n", ptr, size);
    }

    return mem;
}
