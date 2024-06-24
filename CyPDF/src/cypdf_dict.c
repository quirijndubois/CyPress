#include <stdio.h>
#include <stdlib.h>

#include "cypdf_dict.h"
#include "cypdf_list.h"
#include "cypdf_object.h"



void CYPDF_Dict_Obj_Free(CYPDF_Object* obj) {
    free(obj);
}
