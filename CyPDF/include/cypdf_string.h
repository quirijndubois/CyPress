#ifndef CYPDF_STRING_H
#define CYPDF_STRING_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_STRING_OBJ_WRITE          CPYDF_String_Obj_Write
#define CYPDF_STRING_OBJ_FREE           CYPDF_String_Obj_Free


typedef struct _CYPDF_String_obj {
    CYPDF_Obj_Header*       header;
    CYPDF_BYTE*             value;
    CYPDF_SIZE              size;
} CYPDF_String_Obj;


CYPDF_String_Obj* CPYDF_String_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_BYTE* value, CYPDF_SIZE size);

void CPYDF_String_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_String_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_STRING_H */