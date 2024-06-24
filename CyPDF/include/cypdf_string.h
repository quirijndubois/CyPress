#ifndef CYPDF_STRING_H
#define CYPDF_STRING_H


#include "cypdf_object.h"



typedef struct _CYPDF_String_obj {
    CYPDF_Obj_Header    header;
    CYPDF_BYTE*         value;
    CYPDF_SIZE          size;
} CYPDF_String_Obj;



#endif /* CYPDF_STRING_H */