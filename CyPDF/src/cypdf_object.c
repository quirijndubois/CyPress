#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_object.h"
#include "cypdf_array.h"
#include "cypdf_bool.h"
#include "cypdf_catalog.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_doc.h"
#include "cypdf_name.h"
#include "cypdf_null.h"
#include "cypdf_number.h"
#include "cypdf_real.h"
#include "cypdf_stream.h"
#include "cypdf_string.h"



CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 gen, CYPDF_UINT16 class) {
    CYPDF_Obj_Header* header = malloc(sizeof(CYPDF_Obj_Header));
    if (indirect && ID > CYPDF_INDIRECT_OBJ_MAX) {
        printf("Invalid object ID for indirect object.\n");
        free(header);
        return NULL;
    }
    header->obj_id = ID;
    if (direct)
        header->obj_id |= CYPDF_OTYPE_DIRECT;
    if (indirect)
        header->obj_id |= CYPDF_OTYPE_INDIRECT;
    header->obj_gen = gen;
    if (class >= CYPDF_OCLASS_COUNT && class != CYPDF_OCLASS_NONE) {
        printf("Unknown object class.\n");
        class = CYPDF_OCLASS_UNKNOWN;
    }
    header->obj_class = class;

    return header;
}

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header) {
    free(obj_header);
}

CYPDF_Object* CYPDF_Obj_New(CYPDF_Doc* pdf, CYPDF_BOOL direct, CYPDF_BOOL indirect, enum CYPDF_OCLASS class) {
    if (direct)
        ++pdf->obj_count;
    size_t size;
    switch (class)
    {
    case CYPDF_OCLASS_NULL:
        size = sizeof(CYPDF_Null_Obj);
        break;
    case CYPDF_OCLASS_BOOL:
        size = sizeof(CYPDF_Bool_Obj);
        break;
    case CYPDF_OCLASS_NUMBER:
        size = sizeof(CYPDF_Number_Obj);
        break;
    case CYPDF_OCLASS_REAL:
        size = sizeof(CYPDF_Real_Obj);
        break;
    case CYPDF_OCLASS_STRING:
        size = sizeof(CYPDF_String_Obj);
        break;
    case CYPDF_OCLASS_NAME:
        size = sizeof(CYPDF_Name_Obj);
        break;
    case CYPDF_OCLASS_ARRAY:
        size = sizeof(CYPDF_Array_Obj);
        break;
    case CYPDF_OCLASS_DICT:
        size = sizeof(CYPDF_Dict_Obj);
        break;
    case CYPDF_OCLASS_STREAM:
        size = sizeof(CYPDF_Stream_Obj);
        break;
    case CYPDF_OCLASS_CATALOG:
        size = sizeof(CYPDF_Catalog_Obj);
        break;
    default:
        size = sizeof(CYPDF_Null_Obj);
        break;
    }
    CYPDF_Object* obj = calloc(1, size);
    CYPDF_Obj_Header* header = CYPDF_Obj_Header_New(direct, indirect, pdf->obj_count, CYPDF_DEFAULT_OGEN, class);
    memcpy(obj, header, sizeof(*header));
    CYPDF_Obj_Header_Free(header);

    return obj;
}

void CYPDF_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    _obj->funcs.write(fp, obj);
}

void CYPDF_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    _obj->funcs.free(obj);
}
