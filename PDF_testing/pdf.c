#include "pdf.h"

enum ObjectType {
    OBJ_null,
    OBJ_catalog,
};

struct PDFObject;
struct PDFDocument;