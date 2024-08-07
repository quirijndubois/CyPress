#include "cypdf_xref.h"
#include "cypdf_consts.h"
#include "cypdf_doc.h"
#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_print.h"
#include "cypdf_types.h"



void CYPDF_Write_Xref(FILE* fp, CYPDF_Doc* pdf) {
    if (pdf) {
        CYPDF_Obj_List* list = pdf->obj_list;
        CYPDF_SIZE count = list->count;

        CYPDF_fprintf_NL(fp, "xref");
        CYPDF_fprintf_NL(fp, "0 %zu", count + 1);

        CYPDF_fprintf_NL(fp, "%.10zu %.5hu f", 0UL, CYPDF_OGEN_MAX);
        for (size_t i = 0; i < count; ++i) {
            CYPDF_Object* obj = list->objects[i];
            CYPDF_fprintf_NL(fp, "%.10llu %.5hu n", pdf->offsets[i], CYPDF_Obj_Get_Gen(obj));
        }
    }
}