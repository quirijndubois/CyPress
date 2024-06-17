#ifndef CYPDF_NAME_H
#define CYPDF_NAME_H


#include "cypdf_object.h"



#define CYPDF_MAX_NAME_LEN 127


typedef struct _CYPDF_Name_Obj {
    CYPDF_Obj_Header    header;
    char                value[CYPDF_MAX_NAME_LEN + 1];
} CYPDF_Name_Obj;



#endif