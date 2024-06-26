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
    catalog->dict = CYPDF_Dict_Obj_New(ID, CYPDF_TRUE, CYPDF_FALSE);

    return catalog;
}

void CYPDF_Catalog_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Catalog_Obj* catalog = (CYPDF_Catalog_Obj*)obj;
    CYPDF_Obj_Write_Direct(fp, catalog);
}

void CYPDF_Catalog_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Catalog_Obj* _obj = (CYPDF_Catalog_Obj*)obj;
    CYPDF_Obj_Free(_obj->dict);
    free(_obj);
}
