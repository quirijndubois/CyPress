#ifndef CYPDF_DICT_H
#define CYPDF_DICT_H


#include <stdio.h>

#include "cypdf_list.h"
#include "cypdf_name.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_DICT                CYPDF_Write_Dict
#define CYPDF_FREE_DICT                 CYPDF_Free_Dict

#define CYPDF_FREE_DICT_ENTRY           CYPDF_Free_Dict_Entry


/* CYPDF_Obj_Dict struct */
typedef struct _CYPDF_Obj_Dict {
    CYPDF_Obj_Header        header;
    CYPDF_List*             entry_list;
} CYPDF_Obj_Dict;


/* CYPDF_Dict_Entry struct */
typedef struct _CYPDF_Dict_Entry {
    CYPDF_Obj_Name*         key_obj;
    CYPDF_Object*           value_obj;
} CYPDF_Dict_Entry;


/**
 * @brief Creates new CYPDF_Dict_Entry.
 * 
 * @param key 
 * @param value 
 * @return CYPDF_Dict_Entry* | Returns NULL if memory allocation fails.
 */
CYPDF_Dict_Entry* CYPDF_New_Dict_Entry(CYPDF_Obj_Name* key, CYPDF_Object* value);

/**
 * @brief Frees entry. Does nothing if entry is NULL.
 * 
 * @param entry 
 */
void CYPDF_Free_Dict_Entry(CYPDF_Dict_Entry* entry);

/**
 * @brief Creates new CYPDF_Obj_Dict.
 * 
 * @param indirect 
 * @param ID 
 * @return CYPDF_Obj_Dict* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Dict* CYPDF_New_Dict(CYPDF_BOOL indirect, CYPDF_UINT32 ID);

/**
 * @brief Appends the key value pair to dict. Does nothing if dict is NULL.
 * 
 * @param dict 
 * @param key 
 * @param value 
 */
void CYPDF_Dict_Append(CYPDF_Obj_Dict* dict, CYPDF_Obj_Name* key, CYPDF_Object* value);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param dict 
 */
void CYPDF_Write_Dict(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Dict(CYPDF_Object* obj);



#endif /* CYPDF_DICT_H */