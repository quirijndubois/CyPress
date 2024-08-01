#include <stdio.h>
#include <stdlib.h>

#include "cypdf_number.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Number_Obj* CYPDF_Number_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_INT value) {
    CYPDF_Number_Obj* number = (CYPDF_Number_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_NUMBER);
    if (number != NULL) {
        number->value = value;
    }

    return number;
}

void CYPDF_Number_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Number_Obj* number = (CYPDF_Number_Obj*)obj;
    fprintf(fp, "%d", number->value);
}

void CYPDF_Number_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }

    CYPDF_Number_Obj* number = (CYPDF_Number_Obj*)obj;
    free(number);
}
