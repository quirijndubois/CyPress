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
#include "cypdf_page.h"
#include "cypdf_pages.h"
#include "cypdf_real.h"
#include "cypdf_stream.h"
#include "cypdf_string.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Object* CYPDF_New_Obj(CYPDF_BOOL indirect, enum CYPDF_OCLASS class, CYPDF_UINT32 ID) {
    CYPDF_SIZE size = 0;
    CYPDF_Write_Func write_func = NULL;
    CYPDF_Free_Func free_func = NULL;

    /* Assign size, write_func and free_func according to the object class. */
    switch (class)
    {
    case CYPDF_OCLASS_NULL:
        size = sizeof(CYPDF_Obj_Null);
        write_func = CYPDF_WRITE_NULL;
        free_func = CYPDF_FREE_NULL;
        break;
    case CYPDF_OCLASS_BOOL:
        size = sizeof(CYPDF_Obj_Bool);
        write_func = CYPDF_WRITE_BOOL;
        free_func = CYPDF_FREE_BOOL;
        break;
    case CYPDF_OCLASS_NUMBER:
        size = sizeof(CYPDF_Obj_Number);
        write_func = CYPDF_WRITE_NUMBER;
        free_func = CYDPF_FREE_NUMBER;
        break;
    case CYPDF_OCLASS_REAL:
        size = sizeof(CYPDF_Obj_Real);
        write_func = CYPDF_WRITE_REAL;
        free_func = CYPDF_FREE_REAL;
        break;
    case CYPDF_OCLASS_STRING:
        size = sizeof(CYPDF_Obj_String);
        write_func = CYPDF_WRITE_STRING;
        free_func = CYPDF_FREE_STRING;
        break;
    case CYPDF_OCLASS_NAME:
        size = sizeof(CYPDF_Obj_Name);
        write_func = CYPDF_WRITE_NAME;
        free_func = CYPDF_FREE_NAME;
        break;
    case CYPDF_OCLASS_ARRAY:
        size = sizeof(CYPDF_Obj_Array);
        write_func = CYPDF_WRITE_ARRAY;
        free_func = CYPDF_FREE_ARRAY;
        break;
    case CYPDF_OCLASS_DICT:
        size = sizeof(CYPDF_Obj_Dict);
        write_func = CYPDF_WRITE_DICT;
        free_func = CYPDF_FREE_DICT;
        break;
    case CYPDF_OCLASS_STREAM:
        size = sizeof(CYPDF_Obj_Stream);
        break;
    case CYPDF_OCLASS_CATALOG:
        size = sizeof(CYPDF_Obj_Catalog);
        write_func = CYPDF_WRITE_CATALOG;
        free_func = CYPDF_FREE_CATALOG;
        break;
    case CYPDF_OCLASS_PAGE:
        size = sizeof(CYPDF_Obj_Page);
        write_func = CYPDF_WRITE_PAGE;
        free_func = CYPDF_FREE_PAGE;
        break;
    case CYPDF_OCLASS_PAGES:
        size = sizeof(CYPDF_Obj_Pages);
        write_func = CYPDF_WRITE_PAGE;
        free_func = CYPDF_FREE_PAGE;
        break;
    default:
        size = sizeof(CYPDF_Obj_Null);
        write_func = CYPDF_WRITE_NULL;
        free_func = CYPDF_FREE_NULL;
        break;
    }

    CYPDF_Obj_Null* obj = (CYPDF_Obj_Null*)CYPDF_scalloc(1, size);
    if (obj) {
        /* If the given ID is invalid, the default ID is used. */
        if (ID > CYPDF_INDIRECT_OBJ_MAX) {
            ID = CYPDF_DEFAULT_OID;
        }

        /* If the given class doesn't exist, it is set to unknown. */
        if (class > CYPDF_OCLASS_COUNT) {
            class = CYPDF_OCLASS_UNKNOWN;
        }

        if (indirect) {
            obj->header.obj_id = CYPDF_OTYPE_INDIRECT;
        }
        obj->header.obj_id |= (CYPDF_BYTE)class << 24 | ID; /* ID will always be less than 2^24 - 1. */
        obj->header.obj_gen = CYPDF_DEFAULT_OGEN;
        obj->header.write = write_func;
        obj->header.free = free_func;
    }

    return obj;
}

CYPDF_BOOL CYPDF_Obj_isDirect(CYPDF_Object* obj) {
    CYPDF_BOOL direct = CYPDF_FALSE;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        direct = !(CYPDF_BOOL)(_obj->header.obj_id & CYPDF_OTYPE_INDIRECT);
    }

    return direct;
}

enum CYPDF_OCLASS CYPDF_Obj_Get_Class(CYPDF_Object* obj) {
    enum CYPDF_OCLASS class = CYPDF_OCLASS_NONE;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        class = (_obj->header.obj_id & CYPDF_OCLASS_ANY) >> 24;
    }

    return class;
}

CYPDF_UINT32 CYPDF_Obj_Get_ID(CYPDF_Object* obj) {
    CYPDF_UINT32 ID = CYPDF_DEFAULT_OID;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        ID = _obj->header.obj_id & CYPDF_OBJ_ID;
    }

    return ID;
}

CYPDF_UINT16 CYPDF_Obj_Get_Gen(CYPDF_Object* obj) {
    CYPDF_UINT16 gen = CYPDF_DEFAULT_OGEN;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        gen = _obj->header.obj_gen;
    }

    return gen;
}

CYPDF_Write_Func CYPDF_Obj_Get_Write(CYPDF_Object* obj) {
    CYPDF_Write_Func write_func = NULL;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        write_func = _obj->header.write;
    }

    return write_func;
}

CYPDF_Free_Func CYPDF_Obj_Get_Free(CYPDF_Object* obj) {
    CYPDF_Free_Func free_func = NULL;
    if (obj) {
        CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
        free_func = _obj->header.free;
    }

    return free_func;
}

void CYPDF_Write_Obj_Direct(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Write_Func write_func = CYPDF_Obj_Get_Write(obj);
    write_func(fp, obj); /* Writes the object directly. */
}

void CYPDF_Write_Obj_Def(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    /* If the object itself is not indirect, it cannot be written indirectly. 
    This is because it's ID and gen would be invalid. */
    if (!CYPDF_Obj_isDirect(obj)) {
        fprintf(fp, "%u %hu obj\n", CYPDF_Obj_Get_ID(obj), CYPDF_Obj_Get_Gen(obj));
        CYPDF_Write_Obj_Direct(fp, obj);
        fprintf(fp, "\nendobj\n");
    }
}

void CYPDF_Write_Obj_Ref(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    /* If the object itself is not indirect, it cannot be written indirectly. 
    This is because it's ID and gen would be invalid. */
    if (!CYPDF_Obj_isDirect(obj)) {
        fprintf(fp, "%u %hu R", CYPDF_Obj_Get_ID(obj), CYPDF_Obj_Get_Gen(obj));
    }
}

void CYPDF_Free_Obj(CYPDF_Object* obj, CYPDF_BOOL ifIndirect) {
    if (obj) {
        /* An indirect object should only be freed if specified, since multiple attempts to free it might occur. */
        if (CYPDF_Obj_isDirect(obj) || ifIndirect) {
            CYPDF_Obj_Null* _obj = (CYPDF_Obj_Null*)obj;
            _obj->header.free(obj);
        }
    }
}
