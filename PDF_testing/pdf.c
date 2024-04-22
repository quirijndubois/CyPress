#include "pdf.h"

enum ObjectType {
    OBJ_null,
    OBJ_catalog,
};

struct PDF_object {
    int type;
    int index;
    int generation;
};

struct PDF_document {
    void;
};