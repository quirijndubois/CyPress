#include <stdlib.h>

#include "cypdf_null.h"
#include "cypdf_types.h"



CYPDF_Null_Obj* CYPDF_Null_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect) {
    CYPDF_Null_Obj* null = (CYPDF_Null_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_NULL);

    return null;
}

void CYPDF_Null_Obj_Write(FILE* fp __attribute_maybe_unused__, CYPDF_Object* obj __attribute_maybe_unused__) {
    return;
}

void CYPDF_Null_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }

    CYPDF_Null_Obj* null = (CYPDF_Null_Obj*)obj;
    free(null);
}
