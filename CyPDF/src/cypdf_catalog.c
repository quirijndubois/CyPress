#include <stdio.h>
#include <stdlib.h>

#include "cypdf_catalog.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_pages.h"
#include "cypdf_types.h"



CYPDF_Obj_Catalog* CYPDF_New_Catalog(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* pages) {
    CYPDF_Obj_Catalog* catalog = (CYPDF_Obj_Catalog*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_CATALOG, ID);
    if (catalog) {
        catalog->dict = CYPDF_New_Dict(CYPDF_TRUE, ID);
        if (catalog->dict) {
            /* The type of PDF object that this dictionary describes. */
            CYPDF_Obj_Name* type = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Catalog");
            CYPDF_Dict_Append(catalog->dict, CYPDF_TYPE_NAME, type);

            /* The page tree node that is the root of the document’s page tree. */
            CYPDF_Dict_Append(catalog->dict, "Pages", pages);
        }
    }

    return catalog;
}

void CYPDF_Write_Catalog(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Catalog* catalog = (CYPDF_Obj_Catalog*)obj;
    CYPDF_Write_Obj_Direct(fp, catalog->dict);
}

void CYPDF_Free_Catalog(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Catalog* catalog = (CYPDF_Obj_Catalog*)obj;
        CYPDF_Free_Obj(catalog->dict, CYPDF_FALSE);
        free(catalog);
    }
}
