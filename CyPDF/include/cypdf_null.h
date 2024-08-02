#ifndef CYPDF_NULL_H
#define CYPDF_NULL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_NULL_OBJ_WRITE            CYPDF_Null_Obj_Write
#define CYPDF_NULL_OBJ_FREE             CYPDF_Null_Obj_Free


/* CYPDF_Null_Obj struct */
typedef struct _CYPDF_Null_Obj {
    CYPDF_Obj_Header*       header;
} CYPDF_Null_Obj;


/**
 * @brief Creates new CYPDF_Null_Obj.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @return CYPDF_Null_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Null_Obj* CYPDF_Null_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

/**
 * @brief Writes null to fp.
 * 
 * @param fp Stream to be written to.
 * @param null 
 */
void CYPDF_Null_Obj_Write(FILE* fp __attribute_maybe_unused__, CYPDF_Object* obj __attribute_maybe_unused__);

/**
 * @brief Frees NULL. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Null_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_NULL_H */