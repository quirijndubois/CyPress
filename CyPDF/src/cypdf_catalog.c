#include <stdio.h>
#include <stdlib.h>

#include "cypdf_catalog.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_doc.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Catalog_Obj* CYPDF_Catalog_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect) {
    CYPDF_Catalog_Obj* catalog = (CYPDF_Catalog_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_CATALOG);
    if (catalog != NULL) {
        catalog->dict = CYPDF_Dict_Obj_New(ID, CYPDF_TRUE, CYPDF_FALSE);
    }

    return catalog;
}

void CYPDF_Catalog_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Catalog_Obj* catalog = (CYPDF_Catalog_Obj*)obj;

    /* Needs to be implemented. */
}

void CYPDF_Catalog_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }

    CYPDF_Catalog_Obj* _obj = (CYPDF_Catalog_Obj*)obj;
    CYPDF_Obj_Free(_obj->dict);
    free(_obj);
}
