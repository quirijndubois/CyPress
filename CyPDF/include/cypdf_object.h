#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



#define CYPDF_OTYPE_NONE            0x00000000
#define CYPDF_OTYPE_DIRECT          0x80000000
#define CYPDF_OTYPE_INDIRECT        0x40000000
#define CYPDF_OTYPE_ANY             ((CYPDF_OTYPE_DIRECT) | (CYPDF_OTYPE_INDIRECT))

enum CYPDF_OCLASS {
    CYPDF_OCLASS_NULL = 0,
    CYPDF_OCLASS_BOOL,
    CYPDF_OCLASS_NUMBER,
    CYPDF_OCLASS_REAL,
    CYPDF_OCLASS_STRING,
    CYPDF_OCLASS_NAME,
    CYPDF_OCLASS_ARRAY,
    CYPDF_OCLASS_DICT,
    CYPDF_OCLASS_STREAM,        /* A stream is always an indirect object. */

    CYPDF_OCLASS_CATALOG,

    CYPDF_OCLASS_COUNT,

    CYPDF_OCLASS_NONE,
    CYPDF_OCLASS_UNKNOWN,
};

#define CYPDF_OCLASS_ANY            0x00FF


#define CYPDF_DEFAULT_OGEN          0x0000


#define CYPDF_OBJ_ID                0x00FFFFFF


/* object_id structure:
    bit 1:     direct-object
    bit 2:     indirect-object
    bit 3-8:   reserved
    bit 9-32:  object-id

    real Object-ID is described "obj_id & 0x00FFFFFF"
*/

/* CYPDF object header */
typedef struct _CYPDF_Obj_Header {
    CYPDF_UINT32            obj_id;
    CYPDF_UINT16            obj_gen;
    enum CYPDF_OCLASS       obj_class;
    CYPDF_Free_Func         free;
    CYPDF_Write_Func        write;
} CYPDF_Obj_Header;


/**
 * @brief Creates a new CYPDF_Obj_Header for CYPDF_Object's.
 * 
 * @param direct 
 * @param indirect 
 * @param ID 
 * @param gen 
 * @param write 
 * @param free 
 * @return CYPDF_Obj_Header* | Returns NULL if ID is invalid or if memory allocation fails.
 */
CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 gen, CYPDF_UINT16 class, CYPDF_Write_Func write, CYPDF_Free_Func free);

/**
 * @brief Free memory allocated to obj_header.
 * 
 * @param obj_header 
 */
void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header);

/**
 * @brief Creates a new CYPDF_Object.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @param class
 * @return CYPDF_Object* | Returns NULL if header creation fails.
 */
CYPDF_Object* CYPDF_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect, enum CYPDF_OCLASS class);

/**
 * @brief Checks whether obj is direct or not.
 * 
 * @param obj 
 * @return CYPDF_BOOL | Returns CYPDF_FALSE if obj is NULL.
 */
CYPDF_BOOL CYPDF_Obj_Get_Direct(CYPDF_Object* obj);

/**
 * @brief Checks whether obj is indirect or not.
 * 
 * @param obj 
 * @return CYPDF_BOOL | Returns CYPDF_FALSE if obj is NULL.
 */
CYPDF_BOOL CYPDF_Obj_Get_Indirect(CYPDF_Object* obj);

/**
 * @brief Gets the ID of obj.
 * 
 * @param obj 
 * @return CYPDF_UINT32 | Returns CYPDF_OTYPE_NONE if obj is NULL.
 */
CYPDF_UINT32 CYPDF_Obj_Get_ID(CYPDF_Object* obj);

/**
 * @brief Gets the generation number of obj.
 * 
 * @param obj 
 * @return CYPDF_UINT16 | Returns CYPDF_DEFAULT_OGEN if obj is NULL.
 */
CYPDF_UINT16 CYPDF_Obj_Get_Gen(CYPDF_Object* obj);

/**
 * @brief Gets the class of obj.
 * 
 * @param obj 
 * @return enum CYPDF_OCLASS | Returns CYPDF_OCLASS_NONE if obj is NULL.
 */
enum CYPDF_OCLASS CYPDF_Obj_Get_Class(CYPDF_Object* obj);

/**
 * @brief Gets the free function belonging to obj.
 * 
 * @param obj 
 * @return CYPDF_Free_Func | Returns NULL if obj is NULL.
 */
CYPDF_Free_Func CYPDF_Obj_Get_Free(CYPDF_Object* obj);

/**
 * @brief Gets the write function belonging to obj.
 * 
 * @param obj 
 * @return CYPDF_Write_Func | Returns NULL if obj is NULL.
 */
CYPDF_Write_Func CYPDF_Obj_Get_Write(CYPDF_Object* obj);

/**
 * @brief Writes obj as a direct object, either referable or not, depending on it being indirect or not. Writes nothing if fp == NULL or obj == NULL.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Obj_Write_Direct(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Writes obj as an object reference to fp. Writes nothing if fp == NULL or obj == NULL.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Obj_Write_Indirect(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Obj_Free(CYPDF_Object* obj);



#endif /* CYPDF_OBJECT_H */