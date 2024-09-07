#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_stream.h"
#include "cypdf_consts.h"
#include "cypdf_object.h"
#include "cypdf_print.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



CYPDF_Obj_Stream* CYPDF_New_Stream(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_BYTE val, CYPDF_SIZE val_size) {
    CYPDF_Obj_Stream* stream = CYPDF_New_Obj(indirect, CYPDF_OCLASS_STREAM, ID);
    stream->dict = CYPDF_New_Obj(CYPDF_FALSE, CYPDF_OCLASS_DICT, CYPDF_DEFAULT_OID);

    stream->val = CYPDF_smalloc(val_size * sizeof(CYPDF_BYTE));
    memcpy(stream->val, val, val_size);

    return stream;
}

void CYPDF_Write_Stream(FILE* fp, CYPDF_Object* obj) {
    CYPDF_Obj_Stream* stream = (CYPDF_Obj_Stream*)obj;

    CYPDF_Write_Obj_Direct(fp, stream->dict);
    CYPDF_fprintf_NL(fp, "stream");

    fwrite(stream->val, sizeof(stream->val[0]), stream->val_size, fp);

    CYPDF_fprintf_NL(fp, "endstream");
}
