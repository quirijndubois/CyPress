#ifndef CYPDF_NAME_H
#define CYPDF_NAME_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_NAME_OBJ_WRITE            CYPDF_Name_Obj_Write
#define CYPDF_NAME_OBJ_FREE             CYPDF_Name_Obj_Free


#define CYPDF_MAX_NAME_LEN 127


typedef struct _CYPDF_Name_Obj {
    CYPDF_Obj_Header*       header;
    char                    value[CYPDF_MAX_NAME_LEN + 1];
} CYPDF_Name_Obj;


CYPDF_Name_Obj* CYPDF_Name_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, const char* value);

void CYPDF_Name_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Name_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NAME_H */