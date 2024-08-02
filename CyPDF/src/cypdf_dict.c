#include <stdio.h>
#include <stdlib.h>

#include "cypdf_dict.h"
#include "cypdf_consts.h"
#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



static CYPDF_Dict_Entry* CYPDF_New_Dict_Entry(CYPDF_Obj_Name* key, CYPDF_Object* value) {
    CYPDF_Dict_Entry* entry = CYPDF_smalloc(sizeof(CYPDF_Dict_Entry));
    if (entry) {
        entry->key_obj = key;
        entry->value_obj = value;
    }

    return entry;
}

static void CYPDF_Free_Dict_Entry(CYPDF_Dict_Entry* entry) {
    if (entry) {
        CYPDF_Free_Obj(entry->key_obj, CYPDF_FALSE);
        CYPDF_Free_Obj(entry->value_obj, CYPDF_FALSE);
        free(entry);
    }
}

CYPDF_Obj_Dict* CYPDF_New_Dict(CYPDF_BOOL indirect, CYPDF_UINT32 ID) {
    CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_DICT, ID);
    if (dict) {
        dict->entry_list = CYPDF_New_List((CYPDF_Free_Func)CYPDF_FREE_DICT_ENTRY);
    }

    return dict;
}

void CYPDF_Dict_Append(CYPDF_Obj_Dict* dict, CYPDF_Obj_Name* key, CYPDF_Object* value) {
    if (dict) {
        CYPDF_Dict_Entry* entry = CYPDF_New_Dict_Entry(key, value);
        CYPDF_List_Append(dict->entry_list, entry);
    }
}

void CYPDF_Write_Dict(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)obj;
    CYPDF_List* list = dict->entry_list;
    fprintf(fp, "<<%s", CYPDF_NEW_LINE);

    /* Write all dictionary entry object pairs. */
    for(size_t i = 0; i < list->element_count; ++i) {
        CYPDF_Dict_Entry* entry = list->elements[i];
        CYPDF_Write_Obj_Direct(fp, entry->key_obj);
        fputc(' ', fp);
        CYPDF_Write_Obj_Direct(fp, entry->value_obj);
        fprintf(fp, "%s", CYPDF_NEW_LINE);
    }

    fprintf(fp, ">>%s", CYPDF_NEW_LINE);
}

void CYPDF_Free_Dict(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Dict* dict = (CYPDF_Obj_Dict*)obj;
        CYPDF_Free_List(dict->entry_list);
        free(dict);
    }
}