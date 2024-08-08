#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_trailer.h"
#include "cypdf_array.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_doc.h"
#include "md5.h"
#include "cypdf_number.h"
#include "cypdf_object.h"
#include "cypdf_print.h"
#include "cypdf_string.h"
#include "cypdf_types.h"
#include "cypdf_utils.h"



void CYPDF_Write_Trailer(FILE* fp, CYPDF_Doc* pdf, const char* file_path, CYPDF_INT64 xref_offset) {
    CYPDF_Obj_Dict* dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);

    if (dict) {
        CYPDF_Obj_Number* size = CYPDF_New_Number(CYPDF_FALSE, CYPDF_DEFAULT_OID, (CYPDF_INT)pdf->obj_list->count + 1);
        CYPDF_Dict_Append(dict, "Size", size);
        CYPDF_Dict_Append(dict, "Root", pdf->catalog);
        CYPDF_Dict_Append(dict, "Info", pdf->info);

        char* string_to_hash = CYPDF_smalloc(1024 * sizeof(char));
        CYPDF_Obj_Info* info = pdf->info;
        char* date = info->creation_date;
        sprintf(string_to_hash, "%s%s%ld%s%s%s%s%s%s",
                date, file_path, ftell(fp),
                info->title,
                info->author,
                info->subject,
                info->creator,
                info->producer,
                info->creation_date);
        char* id = md5_string(string_to_hash);
        free(string_to_hash);

        CYPDF_Obj_String* ID = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_BYTE, (CYPDF_BYTE*)id, strlen(id));
        free(id);
        CYPDF_Obj_Array* array = CYPDF_New_Array(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        CYPDF_Array_Append(array, ID);
        CYPDF_Array_Append(array, ID);
        CYPDF_Dict_Append(dict, "ID", array);
    }

    CYPDF_fprintf_NL(fp, "trailer");

    CYPDF_Write_Obj_Direct(fp, dict);
    CYPDF_Free_Obj(dict, CYPDF_TRUE);
    CYPDF_Write_NL(fp);

    CYPDF_fprintf_NL(fp, "startxref");
    CYPDF_fprintf_NL(fp, "%lld", xref_offset);
    fprintf(fp, "%%%%EOF");
}