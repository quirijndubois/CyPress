#include "text_pdf_conversion.h"

/*
Copies source file to a new file with the specified name. 
Returns 0 if the copy was succesful, else returns 1.
*/
int copy_file(FILE* source, const char* destination_name) {
    if (!source) return 1;
    FILE* destination = fopen(destination_name, "w");
    char line[256] = { 0 };                                         // We expect the maximum length of a line to be 255 characters.
    while(fgets(line, 256, source)) {
        fputs(line, destination);
    }
    fclose(destination);

    return 0;
}