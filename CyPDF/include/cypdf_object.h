#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



#define CYPDF_OTYPE_NONE            0x00000000
#define CYPDF_OTYPE_DIRECT          0x80000000
#define CYPDF_OTYPE_INDIRECT        0x40000000
#define CYPDF_OTYPE_ANY             (CYPDF_OTYPE_DIRECT) | (CYPDF_OTYPE_INDIRECT)

enum CYPDF_OCLASS {
    CYPDF_OCLASS_NULL = 0,
    CYPDF_OCLASS_BOOL,
    CYPDF_OCLASS_NUMBER,
    CYPDF_OCLASS_REAL,
    CYPDF_OCLASS_STRING,
    CYPDF_OCLASS_NAME,
    CYPDF_OCLASS_ARRAY,
    CYPDF_OCLASS_DICT,
    CYPDF_OCLASS_STREAM,        /* a stream is always an indirect object */

    CYPDF_OCLASS_COUNT,

    CYPDF_OCLASS_NONE,
    CYPDF_OCLASS_UNKNOWN,
};

#define CYPDF_OCLASS_ANY            0x00FF

enum CYPDF_OSUBCLASS {
    CYPDF_OSUBCLASS_CATALOG = 0,

    CYPDF_OSUBCLASS_COUNT,

    CYPDF_OSUBCLASS_NONE,
    CYPDF_OSUBCLASS_UNKNOWN,
};

#define CYPDF_OSUBCLASS_ANY         0xFF00


#define CYPDF_DEFAULT_OGEN          0x0000


/* object_id structure:
    byte 1:     direct-object
    byte 2:     indirect-object
    byte 3-8:   reserved
    byte 9-32:  object-id

    real Object-ID is described "obj_id & 0x00FFFFFF"
*/

/* CYPDF object header */
typedef struct _CYPDF_Obj_Header {
    CYPDF_UINT32 obj_id;
    CYPDF_UINT16 obj_gen;
    CYPDF_UINT16 obj_class;
} CYPDF_Obj_Header;


typedef struct _CYPDF_Obj_Funcs {
    CYPDF_Free_Func         free;
    CYPDF_Write_Func        write;
} CYPDF_Obj_Funcs;


CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 obj_id, CYPDF_UINT16 obj_gen, CYPDF_UINT16 obj_class, CYPDF_UINT16 obj_subclass);

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header);

void CYPDF_Obj_Write(FILE* fp, CYPDF_Object* obj);

void CYPDF_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_OBJECT_H */