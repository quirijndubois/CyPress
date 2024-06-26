#include <stdio.h>
#include <stdlib.h>

#include "cypdf_array.h"
#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Array_Obj* CYPDF_Array_Obj_New(CYPDF_UINT32 ID, CYPDF_BOOL direct, CYPDF_BOOL indirect) {
    CYPDF_Array_Obj* array = (CYPDF_Array_Obj*)CYPDF_Obj_New(ID, direct, indirect, CYPDF_OCLASS_ARRAY);
    array->obj_list = CYPDF_List_New();

    return array;
}

void CYPDF_Array_Obj_Write(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Array_Obj* array = (CYPDF_Array_Obj*)obj;
    CYPDF_List* list = array->obj_list;
    fprintf(fp, "[");
    for (size_t i = 0; i < list->element_count; ++i) {
        CYPDF_Object* _obj = list->elements[i];
        CYPDF_Obj_Write_Direct(fp, _obj);
        if (i + 1 < list->element_count) {
            fprintf(fp, " ");
        }
    }
    fprintf(fp, "]");
}

void CYPDF_Array_Obj_Free(CYPDF_Object* obj) {
    CYPDF_Array_Obj* array = (CYPDF_Array_Obj*)obj;
    CYPDF_List_Free(array->obj_list);
    free(array);
}
