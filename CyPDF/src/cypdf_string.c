#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_string.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_String_Obj* CPYDF_String_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BYTE* value, CYPDF_SIZE vsize) {
    CYPDF_String_Obj* string = (CYPDF_String_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_STRING);
    if (string != NULL) {
        string->value = CYPDF_safe_malloc(vsize);

        /* If memory allocation failed, string->value is not initialized. */
        if (string->value != NULL) {
            memcpy(string->value, value, vsize);
            string->size = vsize;
        } else {
            string->size = 0;
        }
    }

    return string;
}

void CPYDF_String_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_String_Obj* string = (CYPDF_String_Obj*)obj;
    fwrite(string->value, sizeof(string->value[0]), string->size, fp);
}

void CYPDF_String_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }
    
    CYPDF_String_Obj* string = (CYPDF_String_Obj*)obj;
    free(string->value);
    free(string);
}
