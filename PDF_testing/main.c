#include <stdio.h>
#include <string.h>

enum OBJ_type;
struct PDF_object;
struct PDF_file;

int main(void) {
    FILE* source = fopen("test.txt", "r");
    FILE* pdf = fopen("test.pdf", "w");
    
    char line[256] = { 0 };
    while(fgets(line, 256, source)) {
        fputs(line, pdf);
    }

    fclose(source);
    fclose(pdf);

    return 0;
}