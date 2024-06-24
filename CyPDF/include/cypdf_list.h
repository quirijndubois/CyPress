#ifndef CYPDF_LIST_H
#define CYPDF_LIST_H


#include "cypdf_types.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Obj_List {
    CYPDF_SIZE          element_count;
    CYPDF_SIZE          list_size;
    CYPDF_Object**      elements;
} CYPDF_Obj_List;


CYPDF_Obj_List* CYPDF_Obj_List_New();

void CYPDF_Obj_List_Append(CYPDF_Obj_List* list, CYPDF_Object* obj);

void CYPDF_Obj_List_Free(CYPDF_Obj_List* list);



#endif /* CYPDF_LIST_H */