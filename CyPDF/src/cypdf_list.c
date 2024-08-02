#include <stdlib.h>

#include "cypdf_list.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_List* CYPDF_List_New(void (*free_func)(void*)) {
    CYPDF_List* list = CYPDF_safe_calloc(1, sizeof(CYPDF_List));
    if (list != NULL) {
        list->free_element = free_func;
    }

    return list;
}

int CYPDF_List_Append(CYPDF_List* list, void* element) {
    ++list->element_count;
    list->elements = CYPDF_safe_realloc(list->elements, list->element_count * sizeof(void*));
    if (list->elements != NULL) {
        list->elements[list->element_count - 1] = element;
        return 0;
    } else {
        --list->element_count;
        return -1;
    }
}

void CYPDF_List_Free(CYPDF_List* list) {
    if (list == NULL) {
        return;
    }

    for(size_t i = 0; i < list->element_count; ++i) {
        list->free_element(list->elements[i]);
    }
    free(list);
}
