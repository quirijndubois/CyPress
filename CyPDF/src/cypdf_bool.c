#include <stdio.h>
#include <stdlib.h>

#include "cypdf_bool.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Obj_Bool* CYPDF_New_Bool(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_BOOL value) {
    CYPDF_Obj_Bool* bool = (CYPDF_Obj_Bool*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_BOOL, ID);
    if (bool) {
        bool->value = value;
    }

    return bool;
}

void CYPDF_Write_Bool(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Bool* bool = (CYPDF_Obj_Bool*)obj;
    if (bool->value) {
        fprintf(fp, "true");
    } else {
        fprintf(fp, "false");
    }
}

void CYPDF_Free_Bool(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Bool* bool = (CYPDF_Obj_Bool*)obj;
        free(bool);
    }
}
