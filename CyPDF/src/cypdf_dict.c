#include <stdio.h>
#include <stdlib.h>

#include "cypdf_dict.h"
#include "cypdf_consts.h"
#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Dict_Obj* CYPDF_Dict_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect) {
    CYPDF_Dict_Obj* dict = (CYPDF_Dict_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_DICT);
    dict->entry_list = CYPDF_List_New(CYPDF_Dict_Obj_Entry_Free);

    return dict;
}

void CYPDF_Dict_Obj_Append(CYPDF_Dict_Obj* dict, CYPDF_Name_Obj* key, CYPDF_Object* value) {
    CYPDF_Dict_Obj_Entry* entry = CYPDF_Dict_Obj_Entry_New(key, value);
    CYPDF_List_Append(dict->entry_list, entry);
}

void CYPDF_Dict_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Dict_Obj* dict = (CYPDF_Dict_Obj*)obj;
    CYPDF_List* list = dict->entry_list;
    fprintf(fp, "<<%s", CYPDF_NEW_LINE);
    for(size_t i = 0; i < list->element_count; ++i) {
        CYPDF_Dict_Obj_Entry* entry = list->elements[i];
        CYPDF_Obj_Write_Direct(fp, entry->key_obj);
        fprintf(fp, " ");
        CYPDF_Obj_Write_Direct(fp, entry->value_obj);
        fprintf(fp, "%s", CYPDF_NEW_LINE);
    }
    fprintf(fp, ">>%s", CYPDF_NEW_LINE);
}

void CYPDF_Dict_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Dict_Obj* _obj = (CYPDF_Dict_Obj*)obj;
    CYPDF_List_Free(_obj->entry_list);
    free(_obj);
}

CYPDF_Dict_Obj_Entry* CYPDF_Dict_Obj_Entry_New(CYPDF_Name_Obj* key, CYPDF_Object* value) {
    CYPDF_Dict_Obj_Entry* entry = malloc(sizeof(CYPDF_Dict_Obj_Entry));
    entry->key_obj = key;
    entry->value_obj = value;

    return entry;
}

void CYPDF_Dict_Obj_Entry_Free(CYPDF_Dict_Obj_Entry* entry) {
    CYPDF_Obj_Free(entry->key_obj);
    CYPDF_Obj_Free(entry->value_obj);
    free(entry);
}
