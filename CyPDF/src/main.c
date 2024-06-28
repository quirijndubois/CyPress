#include <stdio.h>

#include "cypdf_doc.h"



int main(void) {
    CYPDF_Doc* pdf = CYPDF_Doc_New();
    FILE* fp = fopen("CyPDF/test.txt", "wb");
    CYPDF_Doc_Write(fp, pdf);
    CYPDF_Doc_Free(pdf);
    fclose(fp);

    return 0;
}