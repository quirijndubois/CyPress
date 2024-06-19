#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



#define CYPDF_OCLASS_UNKNOWN        0x0001
#define CYPDF_OCLASS_NULL           0x0002
#define CYPDF_OCLASS_BOOL           0x0003
#define CYPDF_OCLASS_NUMBER         0x0004
#define CYPDF_OCLASS_REAL           0x0005
#define CYPDF_OCLASS_STRING         0x0006
#define CYPDF_OCLASS_NAME           0x0007
#define CYPDF_OCLASS_ARRAY          0x0008
#define CYPDF_OCLASS_DICT           0x0009
// #define CYPDF_OCLASS_STREAM         0x000A, a stream is always an indirect object

#define CYPDF_OCLASS_ANY            0x00FF

#define CYPDF_OCUBCLASS_UNKNOWN     0x0100
#define CYPDF_OSUBCLASS_HEADER      0x0200


/* object_id structure:

*/

/* CYPDF object header */
typedef struct _CYPDF_Obj_Header {
    CYPDF_UINT32 object_id;
    CYPDF_UINT16 gen_num;
    CYPDF_UINT16 obj_class;
} CYPDF_Obj_Header;


typedef void CYPDF_Object;



#endif /* CYPDF_OBJECT_H */