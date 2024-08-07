#include <stdio.h>

#include "cypdf_xref.h"
#include "cypdf_consts.h"
#include "cypdf_doc.h"
#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



void CYPDF_Write_Xref(FILE* fp, CYPDF_Doc* pdf) {
    if (pdf) {
        CYPDF_Obj_List* list = pdf->obj_list;
        CYPDF_SIZE count = list->count;

        fprintf(fp, "\nxref\n");
        fprintf(fp, "0 %zu\n", count + 1);

        fprintf(fp, "%.10zu %.5hu f\n", 0UL, CYPDF_OGEN_MAX);
        for (size_t i = 0; i < count; ++i) {
            CYPDF_Object* obj = list->objects[i];
            fprintf(fp, "%.10llu %.5hu n\n", pdf->offsets[i], CYPDF_Obj_Get_Gen(obj));
        }
    }
}