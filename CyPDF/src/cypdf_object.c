#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_object.h"
#include "cypdf_array.h"
#include "cypdf_bool.h"
#include "cypdf_catalog.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_name.h"
#include "cypdf_null.h"
#include "cypdf_number.h"
#include "cypdf_real.h"
#include "cypdf_stream.h"
#include "cypdf_string.h"
#include "cypdf_utils.h"



CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 gen, CYPDF_UINT16 class, CYPDF_Write_Func write_func, CYPDF_Free_Func free_func) {
    CYPDF_Obj_Header* header = CYPDF_safe_malloc(sizeof(CYPDF_Obj_Header));
    if (!header) {
        return NULL;
    }

    /* If the object's ID exceeds the maximum, the object can't be safely created and NULL is returned. */
    if (ID > CYPDF_INDIRECT_OBJ_MAX) {
        printf("Invalid object ID for indirect object.\n");
        free(header);
        return NULL;
    }
    header->obj_id = ID;

    if (direct)
        header->obj_id |= CYPDF_OTYPE_DIRECT; /* Sets the direct bit of header->obj_id to 1. */
    if (indirect)
        header->obj_id |= CYPDF_OTYPE_INDIRECT; /* Sets the indirect bit of header->obj_id to 1. */
    header->obj_gen = gen;

    /* If the object's class is invalid, it is set to CYPDF_OCLASS_UNKNOWN */
    if (class >= CYPDF_OCLASS_COUNT && class != CYPDF_OCLASS_NONE) {
        printf("Unknown object class.\n");
        class = CYPDF_OCLASS_UNKNOWN;
    }
    header->obj_class = class;

    header->write = write_func;
    header->free = free_func;

    return header;
}

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header) {
    free(obj_header);
}

CYPDF_Object* CYPDF_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, enum CYPDF_OCLASS class) {
    size_t size = 0;
    CYPDF_Write_Func write_func = NULL;
    CYPDF_Free_Func free_func = NULL;

    /* Assign size, write_func and free_func according to the object class. */
    switch (class)
    {
    case CYPDF_OCLASS_NULL:
        size = sizeof(CYPDF_Null_Obj);
        write_func = CYPDF_NULL_OBJ_WRITE;
        free_func = CYPDF_NULL_OBJ_FREE;
        break;
    case CYPDF_OCLASS_BOOL:
        size = sizeof(CYPDF_Bool_Obj);
        write_func = CYPDF_BOOL_OBJ_WRITE;
        free_func = CYPDF_BOOL_OBJ_FREE;
        break;
    case CYPDF_OCLASS_NUMBER:
        size = sizeof(CYPDF_Number_Obj);
        write_func = CYPDF_NUMBER_OBJ_WRITE;
        free_func = CYDPF_NUMBER_OBJ_FREE;
        break;
    case CYPDF_OCLASS_REAL:
        size = sizeof(CYPDF_Real_Obj);
        write_func = CYPDF_REAL_OBJ_WRITE;
        free_func = CYPDF_REAL_OBJ_FREE;
        break;
    case CYPDF_OCLASS_STRING:
        size = sizeof(CYPDF_String_Obj);
        write_func = CYPDF_STRING_OBJ_WRITE;
        free_func = CYPDF_STRING_OBJ_FREE;
        break;
    case CYPDF_OCLASS_NAME:
        size = sizeof(CYPDF_Name_Obj);
        write_func = CYPDF_NAME_OBJ_WRITE;
        free_func = CYPDF_NAME_OBJ_FREE;
        break;
    case CYPDF_OCLASS_ARRAY:
        size = sizeof(CYPDF_Array_Obj);
        write_func = CYPDF_ARRAY_OBJ_WRITE;
        free_func = CYPDF_ARRAY_OBJ_FREE;
        break;
    case CYPDF_OCLASS_DICT:
        size = sizeof(CYPDF_Dict_Obj);
        write_func = CYPDF_DICT_OBJ_WRITE;
        free_func = CYPDF_DICT_OBJ_FREE;
        break;
    case CYPDF_OCLASS_STREAM:
        size = sizeof(CYPDF_Stream_Obj);
        break;
    case CYPDF_OCLASS_CATALOG:
        size = sizeof(CYPDF_Catalog_Obj);
        write_func = CYPDF_CATALOG_OBJ_WRITE;
        free_func = CYPDF_CATALOG_OBJ_FREE;
        break;
    default:
        size = sizeof(CYPDF_Null_Obj);
        write_func = CYPDF_NULL_OBJ_WRITE;
        free_func = CYPDF_NULL_OBJ_FREE;
        break;
    }

    CYPDF_Object* obj = CYPDF_safe_calloc(1, size);
    obj = (CYPDF_Object*)CYPDF_Obj_Header_New(direct, indirect, ID, CYPDF_DEFAULT_OGEN, class, write_func, free_func);
    if (!obj) {
        fprintf(stderr, "Failed to create new object of class %d.\n", class);
    }

    return obj;
}

CYPDF_BOOL CYPDF_Obj_Get_Direct(CYPDF_Object* obj) {
    if (obj == NULL) {
        return CYPDF_FALSE;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return (CYPDF_BOOL)(_obj->header->obj_id & CYPDF_OTYPE_DIRECT);
}

CYPDF_BOOL CYPDF_Obj_Get_Indirect(CYPDF_Object* obj) {
    if (obj == NULL) {
        return CYPDF_FALSE;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->obj_id & CYPDF_OTYPE_INDIRECT;
}

CYPDF_UINT32 CYPDF_Obj_Get_ID(CYPDF_Object* obj) {
    if (obj == NULL) {
        return CYPDF_OTYPE_NONE;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->obj_id & CYPDF_OBJ_ID;
}

CYPDF_UINT16 CYPDF_Obj_Get_Gen(CYPDF_Object* obj) {
    if (obj == NULL) {
        return CYPDF_DEFAULT_OGEN;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->obj_gen;
}

enum CYPDF_OCLASS CYPDF_Obj_Get_Class(CYPDF_Object* obj) {
    if (obj == NULL) {
        return CYPDF_OCLASS_NONE;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->obj_class;
}

CYPDF_Free_Func CYPDF_Obj_Get_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return NULL;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->free;
}

CYPDF_Write_Func CYPDF_Obj_Get_Write(CYPDF_Object* obj) {
    if (obj == NULL) {
        return NULL;
    }

    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    return _obj->header->write;
}

void CYPDF_Obj_Write_Direct(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    /* If the obj is indirect, it means the object will be written indirectly at some point, 
    and therefore it needs to be referable. */
    CYPDF_BOOL indirect = CYPDF_Obj_Get_Indirect(obj);
    if (indirect) {
        fprintf(fp, "%u %hu obj\n", CYPDF_Obj_Get_ID(obj), CYPDF_Obj_Get_Gen(obj));
    }

    CYPDF_Obj_Get_Write(obj)(fp, obj); /* Writes the object directly. */

    if (indirect) {
        fprintf(fp, "endobj\n");
    }
}

void CYPDF_Obj_Write_Indirect(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    /* If the object itself is not indirect, it cannot be written indirectly. 
    This is because it's ID and gen would be invalid. */
    if (!CYPDF_Obj_Get_Indirect(obj)) {
        CYPDF_Obj_Write_Direct(fp, obj);
    } else {
        fprintf(fp, "%u %hu R", CYPDF_Obj_Get_ID(obj), CYPDF_Obj_Get_Gen(obj));
    }
}

void CYPDF_Obj_Free(CYPDF_Object* obj) {
    if (obj == NULL) {
        return;
    }
    
    CYPDF_Null_Obj* _obj = (CYPDF_Null_Obj*)obj;
    CYPDF_Obj_Header* header = _obj->header;
    _obj->header->free(obj);
    free(header);
}
