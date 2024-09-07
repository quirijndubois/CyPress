#ifndef CYPDF_PRINT_H
#define CYPDF_PRINT_H


#include <stdio.h>

#include "cypdf_types.h"



/**
 * @brief Writes buffer followed by an end of line sequence to stream.
 * 
 * @param buffer 
 * @param element_size 
 * @param element_count 
 * @param stream 
 * @return size_t | Returns the amount of bytes successfully written.
 */
size_t CYPDF_fwrite_NL(const void* buffer, size_t element_size, size_t element_count, FILE* stream);

/**
 * @brief Writes an end of line sequence to stream.
 * 
 * @param stream 
 * @return size_t | Returns the amount of bytes successfully written.
 */
size_t CYPDF_Write_NL(FILE* stream);

/**
 * @brief Behaves as fprintf but writes an end of line sequence at the end.
 * 
 * @param stream 
 * @param format 
 * @param ... 
 * @return int | Returns the amount of bytes successfully written.
 */
int CYPDF_fprintf_NL(FILE* stream, const char* format, ...);

/**
 * @brief Writes src as a comment to fp.
 * 
 * @param fp 
 * @param src 
 * @return size_t | Returns the amount of bytes successfully written.
 */
size_t CYPDF_Write_Comment(FILE* fp, const char* src);



#endif /* CYPDF_PRINT_H */
