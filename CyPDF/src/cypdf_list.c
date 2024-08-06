#include <stdlib.h>

#include "cypdf_list.h"
#include "cypdf_consts.h"
#include "cypdf_object.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Obj_List* CYPDF_New_List() {
    CYPDF_Obj_List* list = CYPDF_scalloc(1, sizeof(CYPDF_Obj_List));

    return list;
}

void CYPDF_List_Append(CYPDF_Obj_List* list, CYPDF_Object* obj) {
    ++list->count;
    list->objects = CYPDF_srealloc(list->objects, list->count * sizeof(CYPDF_Object*));
    if (list->objects) {
        list->objects[list->count - 1] = obj;
    } else {
        --list->count;
    }
}

void CYPDF_Free_List(CYPDF_Obj_List* list) {
    if (list) {
        for(size_t i = 0; i < list->count; ++i) {
            CYPDF_Free_Obj(list->objects[i], CYPDF_FALSE);
        }
        free(list);
    }
}
