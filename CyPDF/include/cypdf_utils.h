#ifndef CYPDF_UTILS_H
#define CYPDF_UTILS_H


#include <ctype.h>

#include "cypdf_types.h"



#define MAX(a, b) ((a) > (b) ? (a) : (b))


/**
 * @brief Safely allocates size bytes of memory. Prints an error message if memory allocation fails.
 * 
 * @param size 
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_smalloc(size_t size);

/**
 * @brief Safely calls calloc(element_count, element_size). Prints an error message if memory allocation fails.
 * 
 * @param element_count 
 * @param element_size 
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_scalloc(size_t element_count, size_t element_size);

/**
 * @brief Safely re-allocates ptr to size bytes. Prints an error message if memory allocation fails.
 * 
 * @param ptr Pointer to memory block to be resized.
 * @param size New size of the memory block.
 * @return void* | Returns NULL if memory allocation fails.
 */
void* CYPDF_srealloc(void* ptr, size_t size);

/**
 * @brief Gets current date and time in human readable format required by PDF.
 * 
 * @return char* 
 */
char* CYPDF_Get_Date();



#endif /* CYPDF_UTILS_H */
