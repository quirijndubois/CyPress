#ifndef CYPDF_TRAILER_H
#define CYPDF_TRAILER_H


#include <stdio.h>

#include "cypdf_doc.h"
#include "cypdf_types.h"



/**
 * @brief Writes a trailer to pdf.
 * 
 * @param fp 
 * @param pdf 
 * @param file_path 
 * @param xref_offset 
 */
void CYPDF_Write_Trailer(FILE* fp, CYPDF_Doc* pdf, const char* file_path, CYPDF_INT64 xref_offset);



#endif /* CYPDF_TRAILER_H */
