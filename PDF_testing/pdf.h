#ifndef PDF_H
#define PDF_H

#include <stdio.h>

#define PDF_VERSION "1.7" // Should be determined automatically, need more research for that.
#define HIGH_VAL_BYTES ((char[5]){ -128, -127, -126, -125, '\0' }) // Line that immediately follows header, ensures proper behaviour of file transfer applications.

#define LINE_CHARACTER_LIMIT 255 // The maximum characters on a line is advised to be 255.
#define INFO_CHAR_LIMIT 128


struct PDF_info {
    char title[INFO_CHAR_LIMIT];
    char author[INFO_CHAR_LIMIT];
    char subject[INFO_CHAR_LIMIT];

    char creator[INFO_CHAR_LIMIT];
    char producer[INFO_CHAR_LIMIT];
    char creation_date[INFO_CHAR_LIMIT];
};

struct PDF_object;
struct PDF_doc;

struct PDF_info* pdf_create_info(const char* title, const char* author, const char* subject, const char* creator, const char* producer);
struct PDF_doc* pdf_create(struct PDF_info* info);
void pdf_save(const char* name, const char* dest, struct PDF_doc* pdf);

#endif