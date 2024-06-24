#ifndef CYPDF_CATALOG_H
#define CYPDF_CATALOG_H


#include "cypdf_dict.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Catalog_Obj {
    CYPDF_Obj_Header        header;
    CYPDF_Dict_Obj          dict;
} CYPDF_Catalog_Obj;



#endif /* CYPDF_CATALOG_H */