#ifndef CYPDF_BOOL_H
#define CYPDF_BOOL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_BOOL_OBJ_WRITE            CYPDF_Bool_Obj_Write
#define CYPDF_BOOL_OBJ_FREE             CYPDF_Bool_Obj_Free


typedef struct _CYPDF_Bool_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_BOOL              value;
} CYPDF_Bool_Obj;


CYPDF_Bool_Obj* CYPDF_Bool_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BOOL value);

void CYPDF_Bool_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Bool_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_BOOL_H */