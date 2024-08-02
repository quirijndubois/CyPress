#ifndef CYPDF_STREAM_H
#define CYPDF_STREAM_H


#include "cypdf_dict.h"
#include "cypdf_types.h"



/* CYPDF_Obj_Stream struct */
typedef struct _CYPDF_Obj_Stream {
    CYPDF_Obj_Header        header;
    CYPDF_Obj_Dict          dict;
    CYPDF_BYTE*             value;
    CYPDF_SIZE              size;
} CYPDF_Obj_Stream;



#endif /* CYPDF_STREAM_H */