#include <stdio.h>
#include <stdlib.h>

#include "cypdf_page.h"
#include "cypdf_array.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_name.h"
#include "cypdf_pages.h"
#include "cypdf_types.h"



CYPDF_Obj_Page* CYPDF_New_Page(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_Pages* parent, CYPDF_Rect mediabox_rect __attribute_maybe_unused__) {
    CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_PAGE, ID);
    if (page) {
        page->dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        if (page->dict != NULL) {
            /* The type of the PDF object that this dictionary describes. */
            CYPDF_Obj_Name* type = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Page");
            CYPDF_Dict_Append(page->dict, CYPDF_TYPE_NAME, type);

            /* The page tree node that is the immediate parent of this page object. */
            CYPDF_Dict_Append(page->dict, "Parent", parent);

            /* A dictionary containing any resources required by the page. */
            CYPDF_Obj_Dict* resources = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
            CYPDF_Dict_Append(page->dict, "Resources", resources);

            /* A rectangle, expressed in default user space units, defining the boundaries of the physical medium on which the page is intended to be displayed or printed. */
            CYPDF_Obj_Array* mediabox = CYPDF_Array_From_Rect(mediabox_rect, CYPDF_FALSE, CYPDF_DEFAULT_OID);
            CYPDF_Dict_Append(page->dict, "MediaBox", mediabox);
        }
    }

    return page;
}

void CYPDF_Write_Page(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)obj;
    CYPDF_Write_Obj_Direct(fp, page->dict);
}

void CYPDF_Free_Page(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)obj;
        CYPDF_Free_Obj(page->dict, CYPDF_FALSE);
        free(page);
    }
}