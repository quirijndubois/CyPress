#ifndef CYPDF_DICT_H
#define CYPDF_DICT_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



typedef struct _CYPDF_Dict_Obj {
    CYPDF_Obj_Header    header;
    CYPDF_Obj_Funcs     funcs;
    CYPDF_List*     entry_list;
} CYPDF_Dict_Obj;


typedef struct _CYPDF_Dict_Obj_Entry {
    CYPDF_Name_Obj*     key_obj;
    CYPDF_Object*       value_obj;
} CYPDF_Dict_Obj_Entry;


CYPDF_Dict_Obj* CYPDF_Dict_Obj_New(CYPDF_Doc* pdf, CYPDF_BOOL direct, CYPDF_BOOL indirect);

void CYPDF_Dict_Obj_Append(CYPDF_Dict_Obj* dict, CYPDF_Name_Obj* key, CYPDF_Object* value);

void CYPDF_Dict_Obj_Write(FILE* fp, CYPDF_Dict_Obj* dict);

void CYPDF_Dict_Obj_Free(CYPDF_Object* obj);

CYPDF_Dict_Obj_Entry* CYPDF_Dict_Obj_Entry_New(CYPDF_Name_Obj* key, CYPDF_Object* value);

void CYPDF_Dict_Obj_Entry_Free(CYPDF_Dict_Obj_Entry* entry);



#endif /* CYPDF_DICT_H */