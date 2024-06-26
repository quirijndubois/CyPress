#ifndef CYPDF_REAL_H
#define CYPDF_REAL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_REAL_OBJ_WRITE            CYPDF_Real_Obj_Write
#define CYPDF_REAL_OBJ_FREE             CYPDF_Real_Obj_Free


typedef struct _CYPDF_Real_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_REAL              value;
} CYPDF_Real_Obj;


CYPDF_Real_Obj* CYPDF_Real_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_REAL value);

void CYPDF_Real_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Real_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_REAL_H */