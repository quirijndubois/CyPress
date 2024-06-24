#ifndef CYPDF_REAL_H
#define CYPDF_REAL_H


#include "cypdf_object.h"



typedef struct _CYPDF_Real_Obj {
    CYPDF_Obj_Header    header;
    CYPDF_REAL          value;
} CYPDF_Real_Obj;



#endif /* CYPDF_REAL_H */