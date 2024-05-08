#ifndef PDF_H
#define PDF_H

#define PDF_VERSION "1.7" // Should be determined automatically, need more research for that.
#define COMMENT_LINE ((char[5]){ -128, -127, -126, -125, '\0' }) // Line that immediately follows header, ensures proper behaviour of file transfer applications.

typedef struct PDF_document PDF_document;
struct PDF_document {
    int temp;
};

int construct_pdf(const char* const document_name, const char* const destination_path, PDF_document* const pdf_doc);

#endif