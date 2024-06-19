#ifndef CYPDF_LIST_H
#define CYPDF_LIST_H


#include "cypdf_types.h"
#include "cypdf_object.h"



typedef struct _CYPDF_List {
    CYPDF_SIZE          item_count;
    CYPDF_SIZE          list_size;
    void**              elements;
} CYPDF_List;



#endif /* CYPDF_LIST_H */