#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cypdf_info.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_string.h"
#include "cypdf_utils.h"



CYPDF_Obj_Info* CYPDF_New_Info(CYPDF_BOOL indirect, CYPDF_UINT32 ID, const char* title, const char* author, const char* subject, const char* creator, const char* producer, const char* creation_date) {
    CYPDF_Obj_Info* info = (CYPDF_Obj_Info*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_INFO, ID);

    if (info) {
        snprintf(info->title, CYPDF_INFO_MAX_SIZE, "%s", title);
        snprintf(info->author, CYPDF_INFO_MAX_SIZE, "%s", author);
        snprintf(info->subject, CYPDF_INFO_MAX_SIZE, "%s", subject);
        snprintf(info->creator, CYPDF_INFO_MAX_SIZE, "%s", creator);
        snprintf(info->producer, CYPDF_INFO_MAX_SIZE, "%s", producer);
        snprintf(info->creation_date, CYPDF_INFO_MAX_SIZE, "%s", creation_date);

        info->dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
    }

    return info;
}

void CYPDF_Write_Info(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Info* info = (CYPDF_Obj_Info*)obj;
    CYPDF_Obj_Dict* dict = info->dict;
    CYPDF_Obj_String* string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->title, strlen(info->title));
    CYPDF_Dict_Append(dict, "Title", string);
    string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->author, strlen(info->author));
    CYPDF_Dict_Append(dict, "Author", string);
    string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->subject, strlen(info->subject));
    CYPDF_Dict_Append(dict, "Subject", string);
    string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->creator, strlen(info->creator));
    CYPDF_Dict_Append(dict, "Creator", string);
    string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->producer, strlen(info->producer));
    CYPDF_Dict_Append(dict, "Producer", string);
    string = CPYDF_New_String(CYPDF_FALSE, CYPDF_DEFAULT_OID, CYPDF_STRTYPE_STRING, (CYPDF_BYTE*)info->creation_date, strlen(info->creation_date));
    CYPDF_Dict_Append(dict, "CreationDate", string);

    CYPDF_Write_Obj_Direct(fp, dict);
}

void CYPDF_Free_Info(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Info* info = (CYPDF_Obj_Info*)obj;
        
        CYPDF_Free_Obj(info->dict, CYPDF_FALSE);

        free(info);
    }
}
