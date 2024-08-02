#ifndef CYPDF_NULL_H
#define CYPDF_NULL_H


#include <stdio.h>

#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_NULL            CYPDF_Write_Null
#define CYPDF_FREE_NULL             CYPDF_Free_Null


/* CYPDF_Obj_Null struct */
typedef struct _CYPDF_Obj_Null {
    CYPDF_Obj_Header        header;
} CYPDF_Obj_Null;


/**
 * @brief Creates new CYPDF_Obj_Null.
 * 
 * @param ID 
 * @param indirect 
 * @return CYPDF_Obj_Null* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Null* CYPDF_New_Null(CYPDF_BOOL indirect, CYPDF_UINT32 ID);

/**
 * @brief Writes obj to fp.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Write_Null(FILE* fp __attribute_maybe_unused__, CYPDF_Object* obj __attribute_maybe_unused__);

/**
 * @brief Frees NULL. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Null(CYPDF_Object* obj);



#endif /* CYPDF_NULL_H */