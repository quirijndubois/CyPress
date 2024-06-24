#include <stdio.h>
#include <stdlib.h>

#include "cypdf_dict.h"
#include "cypdf_doc.h"
#include "cypdf_object.h"



CYPDF_Dict_Obj* CYPDF_Dict_Obj_New(CYPDF_Doc* pdf_doc, CYPDF_BOOL direct, CYPDF_BOOL indirect) {
    CYPDF_Obj_Header* obj_header = CYPDF_Obj_Header_New(direct, indirect, CYPDF_OCLASS_DICT, CYPDF_DEFAULT_OGEN, CYPDF_OCLASS_DICT, CYPDF_OSUBCLASS_NONE);
}
