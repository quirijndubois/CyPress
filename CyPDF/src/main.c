#include <stdio.h>

#include "cypdf_doc.h"



int main(void) {
    CYPDF_Doc* pdf = CYPDF_New_Doc();
    FILE* fp = fopen("CyPDF/test.txt", "wb");
    CYPDF_Write_Doc(fp, pdf);
    CYPDF_Free_Doc(pdf);
    fclose(fp);

    return 0;
}