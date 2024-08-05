#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Obj_Name* CYPDF_New_Name(CYPDF_BOOL indirect, CYPDF_UINT32 ID, const char* value) {
    CYPDF_Obj_Name* name = (CYPDF_Obj_Name*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_NAME, ID);
    if (name) {
        memcpy(name->value, value, MAX(strlen(value), CYPDF_MAX_NAME_LEN));
    }

    return name;
}

void CYPDF_Write_Name(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Name* name = (CYPDF_Obj_Name*)obj;
    fprintf(fp, "/%s", name->value);
}

void CYPDF_Free_Name(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Name* name = (CYPDF_Obj_Name*)obj;
        free(name);
    }
}
