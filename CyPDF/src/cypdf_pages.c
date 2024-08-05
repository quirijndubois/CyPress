#include <stdio.h>
#include <stdlib.h>

#include "cypdf_pages.h"
#include "cypdf_array.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_name.h"
#include "cypdf_number.h"
#include "cypdf_object.h"
#include "cypdf_page.h"
#include "cypdf_types.h"



CYPDF_Obj_Pages* CYPDF_New_Pages(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_Pages* parent) {
    CYPDF_Obj_Pages* pages = (CYPDF_Obj_Pages*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_PAGES, ID);
    if (pages) {
        pages->dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        if (pages->dict) {
            /* The type of the PDF object that this dictionary describes. */
            CYPDF_Obj_Name* type_key = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_TYPE_NAME);
            CYPDF_Obj_Name* type_val = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OGEN, "Pages");
            CYPDF_Dict_Append(pages->dict, type_key, type_val);

            if (parent) {
                /* The page tree node that is the immediate parent of this page object. */
                CYPDF_Obj_Name* parent_key = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Parent");
                CYPDF_Dict_Append(pages->dict, parent_key, parent);
            }

            /* An array of indirect references to the immediate children of this node. 
            The children may be page objects or other page tree nodes. */
            CYPDF_Obj_Name* kids_key = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Kids");
            CYPDF_Obj_Array* kids_val = CYPDF_New_Array(CYPDF_FALSE, CYPDF_DEFAULT_OGEN, CYPDF_FREE_PAGE);
            CYPDF_Dict_Append(pages->dict, kids_key, kids_val);

            /* The number of leaf nodes that are descendants of this node within the page tree. */
            CYPDF_Obj_Name* count_key = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Count");
            CYPDF_Obj_Number* count_val = CYPDF_New_Number(CYPDF_FALSE, CYPDF_DEFAULT_OID, 0);
            CYPDF_Dict_Append(pages->dict, count_key, count_val);
        }
    }

    return pages;
}

void CYPDF_Write_Pages(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Pages* pages = (CYPDF_Obj_Pages*)obj;
    CYPDF_Write_Obj_Direct(fp, pages->dict);
}

void CYPDF_Free_Pages(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Pages* pages = (CYPDF_Obj_Pages*)obj;
        CYPDF_Free_Obj(pages->dict, CYPDF_FALSE);
        free(pages);
    }
}