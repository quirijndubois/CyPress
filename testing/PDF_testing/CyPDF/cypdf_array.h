#ifndef CYPDF_ARRAY_H
#define CYPDF_ARRAY_H


#include "cypdf_list.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Array {
    CYPDF_Obj_Header    header;
    CYPDF_List          obj_list;
} CYPDF_Array;



#endif