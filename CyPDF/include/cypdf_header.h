#ifndef CYPDF_HEADER_H
#define CYPDF_HEADER_H


#include <stdio.h>

#include "cypdf_types.h"



#define CYPDF_HIVAL_BYTES       "\x80\x81\x82\x83"


/* CYPDF_File_Header struct */
typedef struct _CYPDF_File_Header {
    char*               version;
    CYPDF_SIZE          version_size;
    char*               hival_bytes;
    CYPDF_SIZE          hival_bytes_size;
} CYPDF_File_Header;


/**
 * @brief Creates new CYPDF_File_Header.
 * 
 * @return CYPDF_File_Header* | Returns NULL if memory allocation fails.
 */
CYPDF_File_Header* CYPDF_New_File_Header();

/**
 * @brief Writes file_header to fp. Does nothing if fp == NULL or file_header == NULL.
 * 
 * @param fp 
 * @param file_header 
 */
void CYPDF_Write_File_Header(FILE* fp, CYPDF_File_Header* file_header);

/**
 * @brief Frees file_header. Does nothing if file_header is NULL.
 * 
 * @param file_header 
 */
void CYPDF_Free_File_Header(CYPDF_File_Header* file_header);



#endif /* CYPDF_HEADER_H */
