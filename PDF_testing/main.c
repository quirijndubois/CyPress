#include <stdio.h>

#include "text_pdf_conversion.h"

enum OBJ_type;
struct PDF_object;
struct PDF_file;

int main(void) {
    FILE* source = fopen("test.pdf", "r");
    if(copy_file(source, "test.txt")) {
        puts("Copy was succesful.");
    } else {
        puts("Copy failed.");
    }

    return 0;
}