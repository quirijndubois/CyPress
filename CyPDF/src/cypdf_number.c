#include <stdio.h>
#include <stdlib.h>

#include "cypdf_number.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Obj_Number* CYPDF_New_Number(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_INT value) {
    CYPDF_Obj_Number* number = (CYPDF_Obj_Number*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_NUMBER, ID);
    if (number) {
        number->value = value;
    }

    return number;
}

void CYPDF_Write_Number(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Number* number = (CYPDF_Obj_Number*)obj;
    fprintf(fp, "%d", number->value);
}

void CYPDF_Free_Number(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Number* number = (CYPDF_Obj_Number*)obj;
        free(number);
    }
}
