#ifndef CYPDF_CATALOG_H
#define CYPDF_CATALOG_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_CATALOG_OBJ_WRITE         CYPDF_Catalog_Obj_Write
#define CYPDF_CATALOG_OBJ_FREE          CYPDF_Catalog_Obj_Free


typedef struct _CYPDF_Catalog_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_Dict_Obj*         dict;
} CYPDF_Catalog_Obj;


CYPDF_Catalog_Obj* CYPDF_Catalog_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

void CYPDF_Catalog_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Catalog_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_CATALOG_H */