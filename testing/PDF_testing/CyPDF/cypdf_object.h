#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



/* object_id structure:

*/

/* CYPDF object header */
typedef struct _CYPDF_obj_header {
    CYPDF_UINT32 object_id;
    CYPDF_UINT16 gen_num;
    CYPDF_UINT16 obj_class;
} CYPDF_obj_header;



#endif