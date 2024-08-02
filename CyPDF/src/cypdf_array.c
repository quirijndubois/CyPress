#include <stdio.h>
#include <stdlib.h>

#include "cypdf_array.h"
#include "cypdf_consts.h"
#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_real.h"
#include "cypdf_types.h"



CYPDF_Obj_Array* CYPDF_New_Array(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Free_Func free_func) {
    CYPDF_Obj_Array* array = (CYPDF_Obj_Array*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_ARRAY, ID);
    if (array) {
        array->obj_list = CYPDF_New_List(free_func);
    }

    return array;
}

CYPDF_Obj_Array* CYPDF_Array_From_Rect(CYPDF_Rect rect, CYPDF_BOOL indirect, CYPDF_UINT32 ID) {
    CYPDF_Obj_Array* array = CYPDF_New_Array(indirect, ID, CYPDF_FREE_REAL);
    if (array != NULL) {
        CYPDF_Obj_Real* coord = CYPDF_New_Real(CYPDF_FALSE, CYPDF_DEFAULT_OID, rect.lowleftx);
        CYPDF_List_Append(array->obj_list, coord);
        coord = CYPDF_New_Real(CYPDF_FALSE, CYPDF_DEFAULT_OID, rect.lowlefty);
        CYPDF_List_Append(array->obj_list, coord);
        coord = CYPDF_New_Real(CYPDF_FALSE, CYPDF_DEFAULT_OID, rect.uprightx);
        CYPDF_List_Append(array->obj_list, coord);
        coord = CYPDF_New_Real(CYPDF_FALSE, CYPDF_DEFAULT_OID, rect.uprighty);
        CYPDF_List_Append(array->obj_list, coord);
    }

    return array;
}

void CYPDF_Write_Array(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Array* array = (CYPDF_Obj_Array*)obj;
    CYPDF_List* list = array->obj_list;
    fputc('[', fp);
    for (size_t i = 0; i < list->element_count; ++i) {
        CYPDF_Object* _obj = list->elements[i];
        CYPDF_Write_Obj_Direct(fp, _obj);
        if (i + 1 < list->element_count) {
            fputc(' ', fp);
        }
    }
    fputc(']', fp);
}

void CYPDF_Free_Array(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Array* array = (CYPDF_Obj_Array*)obj;
        CYPDF_Free_List(array->obj_list);
        free(array);
    }
}
