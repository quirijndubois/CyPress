#ifndef CYPDF_OBJECT_H
#define CYPDF_OBJECT_H


#include "cypdf_types.h"



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

    CYPDF_OCLASS_INFO,
    CYPDF_OCLASS_CATALOG,
    CYPDF_OCLASS_PAGE,
    CYPDF_OCLASS_PNODE,

    CYPDF_OCLASS_COUNT,

    CYPDF_OCLASS_NONE,
    CYPDF_OCLASS_UNKNOWN,
};


#define CYPDF_DEFAULT_OID           0x00000000          /* Used for direct objects. */
#define CYPDF_DEFAULT_OGEN          0x0000


/* CYPDF_Obj_Header struct */
typedef struct _CYPDF_Obj_Header {
    CYPDF_BOOL              indirect;
    enum CYPDF_OCLASS       class;
    CYPDF_UINT32            ID;
    CYPDF_UINT16            gen;
} CYPDF_Obj_Header;


/**
 * @brief Creates a new CYPDF_Object.
 * 
 * @param indirect 
 * @param class
 * @param ID 
 * @return CYPDF_Object* | Returns NULL if header creation fails.
 */
CYPDF_Object* CYPDF_New_Obj(CYPDF_BOOL indirect, enum CYPDF_OCLASS class, CYPDF_UINT32 ID);

/**
 * @brief Checks whether obj is direct or not.
 * 
 * @param obj 
 * @return CYPDF_BOOL | Returns CYPDF_FALSE if obj is NULL.
 */
CYPDF_BOOL CYPDF_Obj_isDirect(CYPDF_Object* obj);

/**
 * @brief Gets the class of obj.
 * 
 * @param obj 
 * @return enum CYPDF_OCLASS | Returns CYPDF_OCLASS_NONE if obj is NULL.
 */
enum CYPDF_OCLASS CYPDF_Obj_Get_Class(CYPDF_Object* obj);

/**
 * @brief Gets the ID of obj.
 * 
 * @param obj 
 * @return CYPDF_UINT32 | Returns CYPDF_DEFAULT_OID if obj is NULL.
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
 * @brief Gets the write function belonging to obj.
 * 
 * @param obj 
 * @return CYPDF_Write_Func | Returns NULL if obj is NULL.
 */
CYPDF_Write_Func CYPDF_Obj_Get_Write(CYPDF_Object* obj);

/**
 * @brief Gets the free function belonging to obj.
 * 
 * @param obj 
 * @return CYPDF_Free_Func | Returns NULL if obj is NULL.
 */
CYPDF_Free_Func CYPDF_Obj_Get_Free(CYPDF_Object* obj);

/**
 * @brief Writes obj as a direct object. Writes nothing if fp == NULL or obj == NULL.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Write_Obj_Direct(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Writes obj as an object definition to fp. Writes nothing if fp == NULL or obj == NULL or if obj is not indirect.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Write_Obj_Def(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Writes obj as an object reference to fp. Does nothing if fp == NULL or obj == NULL or if obj is not indirect.
 * 
 * @param fp Stream to be written to.
 * @param obj 
 */
void CYPDF_Write_Obj_Ref(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL or if obj is indirect and ifIndirect is false.
 * 
 * @param obj 
 * @param ifIndirect If true, allows for obj to be freed even if it is indirect. Use with caution.
 */
void CYPDF_Free_Obj(CYPDF_Object* obj, CYPDF_BOOL ifIndirect);



#endif /* CYPDF_OBJECT_H */