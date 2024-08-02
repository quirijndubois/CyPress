#ifndef CYPDF_LIST_H
#define CYPDF_LIST_H


#include "cypdf_types.h"



/* CYPDF_List struct */
typedef struct _CYPDF_List {
    CYPDF_SIZE          element_count;      /* Number of objects in elements. */
    void**              elements;           /* Array of void pointers likely to be objects or dictionary entries. */
    CYPDF_Free_Func     free_element;       /* Free function corresponding to objects in elements. */
} CYPDF_List;


/**
 * @brief Creates new CYPDF_List initialized with free_func.
 * 
 * @param free_func Function to free the memory allocated to an element of the list.
 * @return CYPDF_List* | Returns NULL if memory allocation fails.
 */
CYPDF_List* CYPDF_List_New(CYPDF_Free_Func free_func);

/**
 * @brief Appends element to list->elements. Does nothing to list if memory allocation for element fails.
 * 
 * @param list 
 * @param element 
 * @return int | Returns 0 on success and -1 on failure.
 */
int CYPDF_List_Append(CYPDF_List* list, void* element);

/**
 * @brief Frees list. Does nothing if list is NULL.
 * 
 * @param list 
 */
void CYPDF_List_Free(CYPDF_List* list);



#endif /* CYPDF_LIST_H */