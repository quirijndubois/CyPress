#ifndef CYPDF_BOOL_H
#define CYPDF_BOOL_H


#include "cypdf_object.h"



typedef struct _CYPDF_Bool_Obj {
    CYPDF_Obj_Header        header;
    CYPDF_BOOL              value;
} CYPDF_Bool_Obj;



#endif /* CYPDF_BOOL_H */