#include <stdio.h>

#include "pdf.h"

int main(void) {
    struct PDF_info* info = pdf_create_info("Hello, World!", "Pieter", "Test", "CyPress Compiler", "CyPress Parser");
    struct PDF_doc* pdf = pdf_create(info);
    for(size_t i = 0; i < 1; ++i) {
        pdf_add_page(pdf, PDF_A4_WIDTH, PDF_A4_HEIGHT);
    }
    pdf_save("hello", NULL, pdf);

    return 0;
}