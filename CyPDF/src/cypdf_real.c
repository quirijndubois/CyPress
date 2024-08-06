#include <stdio.h>
#include <stdlib.h>

#include "cypdf_real.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Obj_Real* CYPDF_New_Real(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_REAL value) {
    CYPDF_Obj_Real* real = (CYPDF_Obj_Real*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_REAL, ID);
    if (real) {
        real->value = value;
    }

    return real;
}

void CYPDF_Write_Real(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Real* real = (CYPDF_Obj_Real*)obj;
    fprintf(fp, "%g", real->value);
}

void CYPDF_Free_Real(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Real* real = (CYPDF_Obj_Real*)obj;
        free(real);
    }
}
