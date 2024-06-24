#include "text_pdf_conversion.h"

int copy_file(const char* source_name, const char* destination_name) {
    if (!source_name) return 0;
    FILE* source = fopen(source_name, "rb");
    if (!source) return 0;
    FILE* destination = fopen(destination_name, "wb");
    if (!destination) return 0;

    char line[256] = { 0 };                         // For small test files a buffer of 256 characters should be enough.
    int count = 0;
    do {
        count = fread(line, 1, 256, source);
        fwrite(line, 1, count, destination);
    } while(count);

    fclose(destination);
    fclose(source);

    return 1;
}