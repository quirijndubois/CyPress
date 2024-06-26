#ifndef CYPDF_NULL_H
#define CYPDF_NULL_H


#include "cypdf_object.h"



#define CYPDF_NULL_OBJ_WRITE            CYPDF_Null_Obj_Write
#define CYPDF_NULL_OBJ_FREE             CYPDF_Null_Obj_Free


typedef struct _CYPDF_Null_Obj {
    CYPDF_Obj_Header*       header;
} CYPDF_Null_Obj;


CYPDF_Null_Obj* CYPDF_Null_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

void CYPDF_Null_Obj_Write();

void CYPDF_Null_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NULL_H */