#include <stdio.h>
#include <string.h>

#include "text_pdf_conversion.h"

enum OBJ_type;
struct PDF_object;
struct PDF_file;

int main(void) {
    FILE* source = fopen("test.pdf", "r");
    copy_file(source, "test.txt");

    return 0;
}