#ifndef CYPDF_ARRAY_H
#define CYPDF_ARRAY_H


#include <stdio.h>

#include "cypdf_list.h"
#include "cypdf_object.h"



#define CYPDF_ARRAY_OBJ_WRITE           CYPDF_Array_Obj_Write
#define CYPDF_ARRAY_OBJ_FREE            CYPDF_Array_Obj_Free


typedef struct _CYPDF_Array_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_List*             obj_list;
} CYPDF_Array_Obj;


CYPDF_Array_Obj* CYPDF_Array_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

void CYPDF_Array_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Array_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_ARRAY_H */