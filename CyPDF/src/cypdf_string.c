#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_string.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Obj_String* CPYDF_New_String(CYPDF_BOOL indirect, CYPDF_UINT32 ID, enum CYPDF_STRING_TYPE type, CYPDF_BYTE* value, CYPDF_SIZE valsize) {
    CYPDF_Obj_String* string = (CYPDF_Obj_String*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_STRING, ID);
    if (string) {
        string->type = type;
        string->value = CYPDF_smalloc(valsize);

        /* If memory allocation failed, string->value is not initialized. */
        if (string->value) {
            memcpy(string->value, value, valsize);
            string->size = valsize;
        } else {
            string->size = 0;
        }
    }

    return string;
}

void CYPDF_Write_String(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_String* string = (CYPDF_Obj_String*)obj;

    switch (string->type)
    {
    case CYPDF_STRTYPE_BYTE:
        fputc('<', fp);
        fwrite(string->value, sizeof(string->value[0]), string->size, fp);
        fputc('>', fp);
        break;
    default:
        fputc('(', fp);
        fwrite(string->value, sizeof(string->value[0]), string->size, fp);
        fputc(')', fp);
        break;
    }
}

void CYPDF_Free_String(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_String* string = (CYPDF_Obj_String*)obj;
        free(string->value);
        free(string);
    }
}
