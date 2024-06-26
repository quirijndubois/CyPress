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

    CYPDF_OCLASS_CATALOG,

    CYPDF_OCLASS_COUNT,

    CYPDF_OCLASS_NONE,
    CYPDF_OCLASS_UNKNOWN,
};

#define CYPDF_OCLASS_ANY            0x00FF


#define CYPDF_DEFAULT_OGEN          0x0000


#define CYPDF_OBJ_ID                0x00FFFFFF


/* object_id structure:
    byte 1:     direct-object
    byte 2:     indirect-object
    byte 3-8:   reserved
    byte 9-32:  object-id

    real Object-ID is described "obj_id & 0x00FFFFFF"
*/

/* CYPDF object header */
typedef struct _CYPDF_Obj_Header {
    CYPDF_UINT32            obj_id;
    CYPDF_UINT16            obj_gen;
    CYPDF_UINT16            obj_class;
    CYPDF_Free_Func         free;
    CYPDF_Write_Func        write;
} CYPDF_Obj_Header;


CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 gen, CYPDF_UINT16 class, CYPDF_Write_Func write, CYPDF_Free_Func free);

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header);

CYPDF_Object* CYPDF_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, enum CYPDF_OCLASS class);

void CYPDF_Obj_Write_Direct(FILE* fp, CYPDF_Object* obj);

void CYPDF_Obj_Write_Indirect(FILE* fp, CYPDF_Object* obj);

void CYPDF_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_OBJECT_H */