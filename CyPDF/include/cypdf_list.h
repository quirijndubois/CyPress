/*
The list structure is not an actual PDF object. 
It is an array of CYPDF_Object pointers to represent, for instance, object arrays or object dictionaries.
*/

#ifndef CYPDF_LIST_H
#define CYPDF_LIST_H


#include "cypdf_types.h"



/* CYPDF_Obj_List struct */
typedef struct _CYPDF_Obj_List {
    CYPDF_SIZE              count;          /* Number of objects. */
    CYPDF_Object**          objects;        /* Array of object pointers. */
} CYPDF_Obj_List;


/**
 * @brief Creates new CYPDF_List.
 * 
 * @return CYPDF_List* | Returns NULL if memory allocation fails.
 */
CYPDF_Obj_List* CYPDF_New_List();

/**
 * @brief Appends element to obj to list. Does nothing to list if memory allocation fails.
 * 
 * @param list 
 * @param obj 
 */
void CYPDF_List_Append(CYPDF_Obj_List* list, CYPDF_Object* obj);

/**
 * @brief Frees list. Does nothing if list is NULL.
 * 
 * @param list 
 */
void CYPDF_Free_List(CYPDF_Obj_List* list);



#endif /* CYPDF_LIST_H */