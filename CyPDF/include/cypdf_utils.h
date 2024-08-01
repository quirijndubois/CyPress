#ifndef CYPDF_UTILS_H
#define CYPDF_UTILS_H


#include <ctype.h>

#include "cypdf_types.h"



#define MAX(a, b) ((a) > (b) ? (a) : (b))


/**
 * @brief Copies characters from src as bytes to dest.
 * 
 * @param src 
 * @param dest 
 * @param size 
 */
void CYPDF_StrToBytes(const char* src, CYPDF_BYTE* dest, size_t size);

/**
 * @brief Safely allocates size bytes of memory. Prints an error message if memory allocation fails.
 * 
 * @param size 
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_safe_malloc(size_t size);

/**
 * @brief Safely calls calloc(element_count, element_size). Prints an error message if memory allocation fails.
 * 
 * @param element_count 
 * @param element_size 
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_safe_calloc(size_t element_count, size_t element_size);

/**
 * @brief Safely re-allocates ptr to size bytes. Prints an error message if memory allocation fails.
 * 
 * @param ptr Pointer to memory block to be resized.
 * @param size New size of the memory block.
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_safe_realloc(void* ptr, size_t size);



#endif /* CYPDF_UTILS_H */