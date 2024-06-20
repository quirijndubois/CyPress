#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



#define CYPDF_OTYPE_NONE            0x00000000
#define CYPDF_OTYPE_DIRECT          0x80000000
#define CYPDF_OTYPE_INDIRECT        0x40000000
#define CYPDF_OTYPE_ANY             (CYPDF_OTYPE_DIRECT) | (CYPDF_OTYPE_INDIRECT)

#define CYPDF_OCLASS_NONE           0x0000
#define CYPDF_OCLASS_UNKNOWN        0x0001
#define CYPDF_OCLASS_NULL           0x0002
#define CYPDF_OCLASS_BOOL           0x0003
#define CYPDF_OCLASS_NUMBER         0x0004
#define CYPDF_OCLASS_REAL           0x0005
#define CYPDF_OCLASS_STRING         0x0006
#define CYPDF_OCLASS_NAME           0x0007
#define CYPDF_OCLASS_ARRAY          0x0008
#define CYPDF_OCLASS_DICT           0x0009
#define CYPDF_OCLASS_STREAM         0x000A      /* a stream is always an indirect object */
#define CYPDF_OCLASS_COUNT          0x000A

#define CYPDF_OCLASS_ANY            0x00FF

#define CYPDF_OSUBCLASS_NONE        0x0000
#define CYPDF_OSUBCLASS_UNKNOWN     0x0100
#define CYPDF_OSUBCLASS_COUNT       0x0001

#define CYPDF_OSUBCLASS_ANY         0xFF00


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


typedef void CYPDF_Object;


CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 obj_id, CYPDF_UINT16 obj_gen, CYPDF_UINT16 obj_class, CYPDF_UINT16 obj_subclass);

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header);



#endif /* CYPDF_OBJECT_H */