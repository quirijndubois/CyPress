#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



/* object_id structure:

*/

/* CYPDF object header */
typedef struct _CYPDF_Obj_Header {
    CYPDF_UINT32 object_id;
    CYPDF_UINT16 gen_num;
    CYPDF_UINT16 obj_class;
} CYPDF_Obj_Header;


typedef void CYPDF_Object;



#endif