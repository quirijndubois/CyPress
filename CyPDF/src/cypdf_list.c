#include <stdlib.h>

#include "cypdf_list.h"
#include "cypdf_object.h"



// CYPDF_Obj_List* CYPDF_Obj_List_New() {
//     CYPDF_Obj_List* list = calloc(1, sizeof(CYPDF_Obj_List));
//     return list;
// }

void CYPDF_Obj_List_Append(CYPDF_Obj_List* list, CYPDF_Object* obj) {
    ++list->list_size;
    list->elements = realloc(list->elements, list->list_size);
    list->elements[list->list_size - 1] = obj;
    ++list->element_count;
}

// void CYPDF_Obj_List_Free(CYPDF_Obj_List* list) {
//     if (list) {
//         for(size_t i = 0; i < list->element_count; ++i) {
//             CYPDF_Obj_Free(list->elements[i]);
//         }
//         free(list);
//     }
// }
