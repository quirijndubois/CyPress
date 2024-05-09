#include <stdio.h>

#include "pdf.h"

int main(void) {
    struct PDF_info* info = pdf_create_info("Test", "Pieter", "Test", "CyPress", "CyPress");
    struct PDF_doc* pdf = pdf_create(info);
    pdf_save("hello", NULL, pdf); // "C:\\Users\\pieterteb\\CyPress\\PDF_testing"

    return 0;
}