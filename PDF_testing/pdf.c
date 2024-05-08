#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pdf.h"

enum ObjectType {
    OBJ_null,
    OBJ_catalog,
};

typedef struct PDF_object PDF_object;
struct PDF_object {
    int type;
    int index;
    int generation;
};


int construct_pdf(const char* const document_name, const char* const destination_path, PDF_document* const pdf_doc) {
    size_t destination_length = strlen(destination_path);
    size_t path_length = strlen(document_name) + destination_length + 6; // 6 is added to account for the '\' character between destination_path and document_name, the ".pdf" extension and the '\0' character.
    char* file_path = malloc(path_length * sizeof(char));
    if (!file_path) {
        return -1;
    }
    strcpy(file_path, destination_path);
    file_path[destination_length] = '\\';
    strcat(file_path, document_name);
    strcat(file_path, ".txt");

    FILE* fileptr = fopen(file_path, "wb"); // The file is written in binary since pdf requires byte values which can be misinterpreted as characters.

    // Write header of pdf.
    fprintf(fileptr, "%%PDF-%s\n", PDF_VERSION);
    fprintf(fileptr, "%%%s\n", COMMENT_LINE);

    free(file_path);
    free(pdf_doc);

    fwrite("%%EOF\n", sizeof(char), 6, fileptr);
    fclose(fileptr);

    return 0;
}