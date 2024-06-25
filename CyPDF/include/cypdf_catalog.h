#ifndef CYPDF_CATALOG_H
#define CYPDF_CATALOG_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Catalog_Obj {
    CYPDF_Obj_Header        header;
    CYPDF_Obj_Funcs         funcs;
    CYPDF_Dict_Obj*         dict;
} CYPDF_Catalog_Obj;


CYPDF_Catalog_Obj* CYPDF_Catalog_Obj_New();

void CYPDF_Catalog_Obj_Write(FILE* fp, CYPDF_Catalog_Obj* catalog);

void CYPDF_Catalog_Obj_Free(CYPDF_Object* catalog);



#endif /* CYPDF_CATALOG_H */