#ifndef PDF_H
#define PDF_H

#include <stdio.h>

#define PDF_VERSION "1.7" // Should be determined automatically, need more research for that.
#define PDF_HIGH_VAL_BYTES ((char[5]){ -128, -127, -126, -125, '\0' }) // Line that immediately follows header, ensures proper behaviour of file transfer applications.

#define PDF_LINE_CHARACTER_LIMIT 255 // The maximum characters on a line is advised to be 255.
#define PDF_INFO_CHAR_LIMIT 128

#define PDF_PAGE_DIMENSION_LIMIT 14400

#define PDF_INCH_TO_POINT(inch) ((float)(inch * 72.0f))
#define PDF_MM_TO_POINT(mm) ((float)(mm * 72.0f / 25.4f))

#define PDF_A4_WIDTH PDF_MM_TO_POINT(210.0f)
#define PDF_A4_HEIGHT PDF_MM_TO_POINT(297.0f)
#define PDF_A3_WIDTH PDF_MM_TO_POINT(297.0f)
#define PDF_A3_HEIGHT PDF_MM_TO_POINT(420.0f)


struct PDF_info {
    char title[PDF_INFO_CHAR_LIMIT];
    char author[PDF_INFO_CHAR_LIMIT];
    char subject[PDF_INFO_CHAR_LIMIT];

    char creator[PDF_INFO_CHAR_LIMIT];
    char producer[PDF_INFO_CHAR_LIMIT];
    char creation_date[PDF_INFO_CHAR_LIMIT];
};

struct PDF_object;
struct PDF_object_page_leaf;
struct PDF_doc;

struct PDF_info* pdf_create_info(const char* title, const char* author, const char* subject, const char* creator, const char* producer);
struct PDF_object* pdf_add_page(struct PDF_doc* pdf, float width, float height);
struct PDF_object* pdf_add_content_stream(struct PDF_doc* pdf, const char* content, struct PDF_object* page);
struct PDF_doc* pdf_create(struct PDF_info* info);
void pdf_save(const char* name, const char* dest, struct PDF_doc* pdf);

#endif