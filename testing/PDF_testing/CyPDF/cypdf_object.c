#include <stdio.h>
#include <stdlib.h>

#include "cypdf_object.h"
#include "cypdf_consts.h"
#include "cypdf_null.h"



CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 obj_gen, CYPDF_UINT16 obj_class, CYPDF_UINT16 obj_subclass) {
    CYPDF_Obj_Header* obj_header = malloc(sizeof(CYPDF_Obj_Header));
    direct = !!direct;
    indirect = !!indirect;
    if (indirect && ID > CYPDF_INDIRECT_OBJ_MAX) {
        printf("Invalid object ID for indirect object.\n");
        free(obj_header);
        return NULL;
    }
    obj_header->obj_id = ID;
    if (direct) {
        obj_header->obj_id |= CYPDF_OTYPE_DIRECT;
    }
    if (indirect) {
        obj_header->obj_id |= CYPDF_OTYPE_INDIRECT;
    }
    obj_header->obj_gen = obj_gen;
    if (obj_class > CYPDF_OCLASS_COUNT) {
        printf("Unknown object class.\n");
        obj_class = CYPDF_OCLASS_UNKNOWN;
    }
    if (obj_subclass & CYPDF_OCLASS_ANY || (obj_subclass >> 8) > CYPDF_OSUBCLASS_COUNT) {
        printf("Unknown object subclass.\n");
        obj_subclass = CYPDF_OSUBCLASS_UNKNOWN;
    }
    obj_header->obj_class = obj_class | obj_subclass;

    return obj_header;
}

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header) {
    free(obj_header);
}

void CYPDF_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    _obj->funcs.write(fp, obj);
}

void CYPDF_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    _obj->funcs.free(obj);
}
