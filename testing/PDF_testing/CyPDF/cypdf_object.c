#include "cypdf_object.h"
#include "cypdf_consts.h"



CYPDF_Obj_Header* CYPDF_Obj_Header_New(CYPDF_BOOL direct, CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_UINT16 obj_gen, CYPDF_UINT16 obj_class) {
    CYPDF_Obj_Header* obj_header = malloc(sizeof(CYPDF_Obj_Header));
    direct = !!direct;
    indirect = !!indirect;
    if (indirect && ID > CYPDF_INDIRECT_OBJ_MAX) {
        printf("Invalid object ID for indirect object.\n");
        free(obj_header);
        return NULL;
    }
    obj_header->obj_id = direct * CYPDF_OTYPE_DIRECT | indirect * CYPDF_OTYPE_INDIRECT | ID;
    obj_header->obj_gen = obj_gen;
    obj_header->obj_class = obj_class;

    return obj_header;
}

void CYPDF_Obj_Header_Free(CYPDF_Obj_Header* obj_header) {
    free(obj_header);
}
