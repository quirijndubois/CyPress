#ifndef CYPDF_NULL_H
#define CYPDF_NULL_H


#include "cypdf_object.h"



typedef struct _CYPDF_Null_Obj {
    CYPDF_Obj_Header    header;
    CYPDF_Obj_Funcs     funcs;
} CYPDF_Null_Obj;



#endif /* CYPDF_NULL_H */