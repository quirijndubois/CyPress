#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_string.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_String_Obj* CPYDF_String_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BYTE* value, CYPDF_SIZE size) {
    CYPDF_String_Obj* string = (CYPDF_String_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_STRING);
    string->value = malloc(size);
    memcpy(string->value, value, size);
    string->size = size;

    return string;
}

void CPYDF_String_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_String_Obj* string = (CYPDF_String_Obj*)obj;
    fwrite(string->value, sizeof(string->value[0]), string->size, fp);
}

void CYPDF_String_Obj_Free(CYPDF_Object* obj) {
    CYPDF_String_Obj* string = (CYPDF_String_Obj*)obj;
    free(string->value);
    free(string);
}
