#include <stdio.h>
#include <stdlib.h>

#include "cypdf_dict.h"
#include "cypdf_consts.h"
#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_print.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Obj_Dict* CYPDF_New_Dict(CYPDF_BOOL indirect, CYPDF_UINT32 ID) {
    CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_DICT, ID);
    if (dict) {
        dict->keys = CYPDF_New_List();
        dict->values = CYPDF_New_List();
        dict->count = 0;
    }

    return dict;
}

void CYPDF_Dict_Append(CYPDF_Obj_Dict* dict, const char* key_name, CYPDF_Object* value) {
    if (dict) {
        CYPDF_Obj_Name* key = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, key_name);
        CYPDF_List_Append(dict->keys, key);
        CYPDF_List_Append(dict->values, value);
        ++dict->count;
    }
}

void CYPDF_Write_Dict(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)obj;
    CYPDF_Obj_List* keys = dict->keys;
    CYPDF_Obj_List* values = dict->values;

    fprintf(fp, "<<%s", CYPDF_NEW_LINE);

    /* Write all dictionary entry object pairs. */
    for(size_t i = 0; i < dict->count; ++i) {
        CYPDF_Write_Obj_Direct(fp, keys->objects[i]);
        fputc(' ', fp);

        if (CYPDF_Obj_isDirect(values->objects[i])) {
            CYPDF_Write_Obj_Direct(fp, values->objects[i]);
        } else {
            CYPDF_Write_Obj_Ref(fp, values->objects[i]);
        }
        
        CYPDF_Write_NL(fp);
    }

    fprintf(fp, ">>");
}

void CYPDF_Free_Dict(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)obj;
        CYPDF_Free_List(dict->keys);
        CYPDF_Free_List(dict->values);
        free(dict);
    }
}