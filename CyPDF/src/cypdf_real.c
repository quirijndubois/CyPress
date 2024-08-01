#include <stdio.h>
#include <stdlib.h>

#include "cypdf_real.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Real_Obj* CYPDF_Real_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_REAL value) {
    CYPDF_Real_Obj* real = (CYPDF_Real_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_REAL);
    if (real != NULL) {
        real->value = value;
    }

    return real;
}

void CYPDF_Real_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Real_Obj* real = (CYPDF_Real_Obj*)obj;
    fprintf(fp, "%f", real->value);
}

void CYPDF_Real_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }
    
    CYPDF_Real_Obj* real = (CYPDF_Real_Obj*)obj;
    free(real);
}
