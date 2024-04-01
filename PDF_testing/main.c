#include "text_pdf_conversion.h"

#include <stdio.h>

int main(void) {
    if(copy_file("pdf_flatedecode\\main.pdf", "pdf_flatedecode\\main.txt")) {
        puts("Copy was succesful.");
    } else {
        puts("Copy failed.");
    }

    return 0;
}