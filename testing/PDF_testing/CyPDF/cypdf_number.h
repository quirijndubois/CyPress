#ifndef CYPDF_NUMBER_H
#define CYPDF_NUMBER_H


#include "cypdf_object.h"



typedef struct _CYPDF_Number_Obj {
    CYPDF_Obj_Header    header;
    CYPDF_INT           value;
} CYPDF_Number_Obj;



#endif /* CYPDF_NUMBER_H */