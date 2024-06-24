#ifndef CYPDF_DICT_H
#define CYPDF_DICT_H


#include "cypdf_doc.h"
#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Dict_Obj {
    CYPDF_Obj_Header    header;
    CYPDF_Obj_Funcs     funcs;
    CYPDF_Obj_List      entry_list;
} CYPDF_Dict_Obj;


typedef struct _CYPDF_Dict_Entry {
    CYPDF_Name_Obj*     key_obj;
    CYPDF_Object*       value_obj;
} CYPDF_Dict_Entry;


CYPDF_Dict_Obj* CYPDF_Dict_Obj_New(CYPDF_Doc* pdf_doc, CYPDF_BOOL direct, CYPDF_BOOL indirect);



#endif /* CYPDF_DICT_H */