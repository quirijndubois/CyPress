#include "pdf.h"

enum ObjectType {
    OBJ_null,
    OBJ_catalog,
};

struct PDFObject {
    int type;
    int index;
    int generation;

};

struct PDFDocument {
    void;
}