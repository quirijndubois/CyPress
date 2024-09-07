#ifndef CYPDF_STREAM_H
#define CYPDF_STREAM_H


#include <stdio.h>

#include "cypdf_dict.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_STREAM                      CYPDF_Write_Stream
#define CYPDF_FREE_STREAM                       CYPDF_Free_Stream


/* CYPDF_Obj_Stream struct */
typedef struct _CYPDF_Obj_Stream {
    CYPDF_Obj_Header        header;

    CYPDF_Obj_Dict*         dict;
    CYPDF_BYTE*             val;
    CYPDF_SIZE              val_size;
} CYPDF_Obj_Stream;



#endif /* CYPDF_STREAM_H */
