#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Name_Obj* CYPDF_Name_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, const char* value) {
    CYPDF_Name_Obj* name = (CYPDF_Name_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_NAME);
    memcpy(name->value, value, MAX(strlen(value), CYPDF_MAX_NAME_LEN));

    return name;
}

void CYPDF_Name_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Name_Obj* name = (CYPDF_Name_Obj*)obj;
    fprintf(fp, "/%s", name->value);
}

void CYPDF_Name_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Name_Obj* name = (CYPDF_Name_Obj*)obj;
    free(name);
}
