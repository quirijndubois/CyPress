#ifndef CYPDF_PRINT_H
#define CYPDF_PRINT_H


#include <stdio.h>

#include "cypdf_types.h"



/**
 * @brief Writes buffer followed by CYPDF_NEW_LINE to fp. Does nothing if buffer == NULL or fp == NULL.
 * 
 * @param buffer 
 * @param element_size 
 * @param element_count 
 * @param fp Stream to be written to.
 */
void CYPDF_fwrite_LF(const void* buffer, size_t element_size, size_t element_count, FILE* fp);

/**
 * @brief Writes src to fp in the form of a PDF comment. Does nothing if fp == NULL or src == NULL.
 * 
 * @param fp 
 * @param src 
 * @param size 
 */
void CYPDF_Write_Comment(FILE* fp, CYPDF_BYTE* src, size_t size);



#endif /* CYPDF_PRINT_H */