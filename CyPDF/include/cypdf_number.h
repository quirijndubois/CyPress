#ifndef CYPDF_NUMBER_H
#define CYPDF_NUMBER_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_NUMBER_OBJ_WRITE          CYPDF_Number_Obj_Write
#define CYDPF_NUMBER_OBJ_FREE           CYPDF_Number_Obj_Free


typedef struct _CYPDF_Number_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_INT               value;
} CYPDF_Number_Obj;


CYPDF_Number_Obj* CYPDF_Number_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_INT value);

void CYPDF_Number_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Number_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NUMBER_H */