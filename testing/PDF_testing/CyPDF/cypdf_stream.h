#ifndef CYPDF_STREAM_H
#define CYPDF_STREAM_H


#include "cypdf_dict.h"
#include "cypdf_mmgr.h"
#include "cypdf_object.h"



typedef struct _CYPDF_Stream_Obj {
    CYPDF_MMgr          mmgr;
    CYPDF_Dict_Obj      dict;
    CYPDF_BYTE*         value;
    CYPDF_SIZE          size;
} CYPDF_Stream_Obj;



#endif /* CYPDF_STREAM_H */