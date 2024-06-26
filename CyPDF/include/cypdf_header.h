#ifndef CYPDF_HEADER_H
#define CYPDF_HEADER_H


#include <stdio.h>

#include "cypdf_types.h"



#define CYPDF_HIVAL_BYTES       "\x80\x81\x82\x83"


typedef struct _CYPDF_File_Header {
    CYPDF_BYTE*         version;
    CYPDF_SIZE          version_size;
    CYPDF_BYTE*         hival_bytes;
    CYPDF_SIZE          hival_bytes_size;
} CYPDF_File_Header;


CYPDF_File_Header* CYPDF_File_Header_New();

void CYPDF_File_Header_Write(FILE* fp, CYPDF_File_Header* file_header);

void CYPDF_File_Header_Free(CYPDF_File_Header* file_header);



#endif /* CYPDF_HEADER_H */