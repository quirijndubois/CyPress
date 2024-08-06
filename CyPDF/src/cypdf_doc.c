#include <stdio.h>
#include <stdlib.h>

#include "cypdf_doc.h"
#include "cypdf_array.h"
#include "cypdf_catalog.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_header.h"
#include "cypdf_list.h"
#include "cypdf_object.h"
#include "cypdf_pages.h"
#include "cypdf_utils.h"



CYPDF_Doc* CYPDF_New_Doc() {
    CYPDF_Doc* pdf_doc = CYPDF_smalloc(sizeof(CYPDF_Doc));
    if (pdf_doc) {
        pdf_doc->file_header = CYPDF_New_File_Header();
        pdf_doc->curr_ID = 1;

        pdf_doc->page_tree = CYPDF_New_PNode(CYPDF_TRUE, pdf_doc->curr_ID++, NULL);
        pdf_doc->catalog = CYPDF_New_Catalog(CYPDF_TRUE, pdf_doc->curr_ID++, pdf_doc->page_tree);

        pdf_doc->obj_list = CYPDF_New_List();
        CYPDF_List_Append(pdf_doc->obj_list, pdf_doc->catalog);
        CYPDF_List_Append(pdf_doc->obj_list, pdf_doc->page_tree);
    }

    return pdf_doc;
}

void CYPDF_Append_Page(CYPDF_Doc* pdf_doc) {
    CYPDF_Obj_Page* page = CYPDF_Add_Page(pdf_doc->page_tree, pdf_doc->curr_ID++, CYPDF_A4_MEDIABOX);
    CYPDF_List_Append(pdf_doc->obj_list, page);
}

void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf_doc) {
    if (fp == NULL || pdf_doc == NULL) {
        return;
    }

    CYPDF_Write_File_Header(fp, pdf_doc->file_header);

    CYPDF_Obj_List* list = pdf_doc->obj_list;
    for (size_t i = 0; i < list->count; ++i) {
        CYPDF_Write_Obj_Def(fp, list->objects[i]);
    }
}

void CYPDF_Free_Doc(CYPDF_Doc* pdf_doc) {
    if (pdf_doc) {
        CYPDF_Free_File_Header(pdf_doc->file_header);

        CYPDF_Obj_List* list = pdf_doc->obj_list;
        for (size_t i = 0; i < list->count; ++i) {
            CYPDF_Free_Obj(list->objects[i], CYPDF_TRUE);
        }

        free(pdf_doc);
    }
}