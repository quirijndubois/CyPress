#ifndef CYPDF_DICT_H
#define CYPDF_DICT_H


#include <stdio.h>

#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_DICT_OBJ_WRITE            CYPDF_Dict_Obj_Write
#define CYPDF_DICT_OBJ_FREE             CYPDF_Dict_Obj_Free

#define CYPDF_DICT_OBJ_ENTRY_FREE       CYPDF_Dict_Obj_Entry_Free


/* CYPDF_Dict_Obj struct */
typedef struct _CYPDF_Dict_Obj {
    CYPDF_Obj_Header*       header;
    CYPDF_List*             entry_list;
} CYPDF_Dict_Obj;


/* CYPDF_Dict_Obj_Entry struct */
typedef struct _CYPDF_Dict_Obj_Entry {
    CYPDF_Name_Obj*     key_obj;
    CYPDF_Object*       value_obj;
} CYPDF_Dict_Obj_Entry;


/**
 * @brief Creates new CYPDF_Dict_Obj.
 * 
 * @param ID 
 * @param direct 
 * @param indirect 
 * @return CYPDF_Dict_Obj* | Returns NULL if object creation fails.
 */
CYPDF_Dict_Obj* CYPDF_Dict_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect);

/**
 * @brief Appends the key value pair to dict. Does nothing if dict is NULL.
 * 
 * @param dict 
 * @param key 
 * @param value 
 */
void CYPDF_Dict_Obj_Append(CYPDF_Dict_Obj* dict, CYPDF_Name_Obj* key, CYPDF_Object* value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param dict 
 */
void CYPDF_Dict_Obj_Write(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Dict_Obj_Free(CYPDF_Object* obj);

/**
 * @brief Creates new CYPDF_Dict_Obj_Entry initialized with the key value pair.
 * 
 * @param key 
 * @param value 
 * @return CYPDF_Dict_Obj_Entry* | Returns NULL if memory allocation fails.
 */
CYPDF_Dict_Obj_Entry* CYPDF_Dict_Obj_Entry_New(CYPDF_Name_Obj* key, CYPDF_Object* value);

/**
 * @brief Frees entry. Does nothing if entry is NULL.
 * 
 * @param entry 
 */
void CYPDF_Dict_Obj_Entry_Free(CYPDF_Dict_Obj_Entry* entry);



#endif /* CYPDF_DICT_H */