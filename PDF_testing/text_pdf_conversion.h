#ifndef TEXT_PDF_CONVERSION_H
#define TEXT_PDF_CONVERSION_H

#include <stdio.h>

/**
 * @brief Copies source file to a new file with the specified name. 
 * Returns 1 if the copy was succesful, else returns 0.
 * 
 * @param source Source file
 * @param destination_name Name of destination file
 * @return 1 if succesful, 0 else
 */
int copy_file(FILE* source, const char* destination_name);

#endif