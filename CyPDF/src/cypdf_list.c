#include <stdlib.h>

#include "cypdf_list.h"
#include "cypdf_object.h"



CYPDF_List* CYPDF_List_New() {
    CYPDF_List* list = calloc(1, sizeof(CYPDF_List));
    return list;
}

void CYPDF_List_Append(CYPDF_List* list, void* element) {
    ++list->list_size;
    list->elements = realloc(list->elements, list->list_size);
    list->elements[list->list_size - 1] = element;
    ++list->element_count;
}

void CYPDF_List_Free(CYPDF_List* list) {
    if (list) {
        for(size_t i = 0; i < list->element_count; ++i) {
            list->free_element(list->elements[i]);
        }
        free(list);
    }
}
