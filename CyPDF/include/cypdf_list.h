#ifndef CYPDF_LIST_H
#define CYPDF_LIST_H


#include "cypdf_types.h"



typedef struct _CYPDF_List {
    CYPDF_SIZE          element_count;
    CYPDF_SIZE          list_size;
    CYPDF_Object**      elements;
    CYPDF_Free_Func     free_element;
} CYPDF_List;


CYPDF_List* CYPDF_List_New();

void CYPDF_List_Append(CYPDF_List* list, void* element);

void CYPDF_List_Free(CYPDF_List* list);



#endif /* CYPDF_LIST_H */