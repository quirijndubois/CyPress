#ifndef CYPDF_MMGR_H
#define CYPDF_MMGR_H


#include "cypdf_object.h"



typedef struct _CYPDF_MMgr {
    CYPDF_Alloc_Func        alloc;
    CYPDF_Free_Func         free;
    CYPDF_SIZE              size;
} CYPDF_MMgr;



#endif /* CYPDF_MMGR_H */