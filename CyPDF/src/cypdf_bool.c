#include <stdio.h>
#include <stdlib.h>

#include "cypdf_bool.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Bool_Obj* CYPDF_Bool_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BOOL value) {
    CYPDF_Bool_Obj* bool = (CYPDF_Bool_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_BOOL);
    bool->value = value;

    return bool;
}

void CYPDF_Bool_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Bool_Obj* bool = (CYPDF_Bool_Obj*)obj;
    if (bool->value) {
        fprintf(fp, "true");
    } else {
        fprintf(fp, "false");
    }
}

void CYPDF_Bool_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Bool_Obj* bool = (CYPDF_Bool_Obj*)obj;
    free(bool);
}
