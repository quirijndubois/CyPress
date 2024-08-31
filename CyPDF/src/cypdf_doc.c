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
#include "cypdf_print.h"
#include "cypdf_trailer.h"
#include "cypdf_utils.h"
#include "cypdf_xref.h"



CYPDF_Doc* CYPDF_New_Doc() {
    CYPDF_Doc* pdf = CYPDF_smalloc(sizeof(CYPDF_Doc));
    if (pdf) {
        pdf->file_header = CYPDF_New_File_Header();
        pdf->curr_ID = 1;
        pdf->offsets = NULL;

        pdf->page_tree = CYPDF_New_PNode(CYPDF_TRUE, pdf->curr_ID++, NULL);                 /* Page root. */
        pdf->catalog = CYPDF_New_Catalog(CYPDF_TRUE, pdf->curr_ID++, pdf->page_tree);

        char* creation_date = CYPDF_Get_Date();
        pdf->info = CYPDF_New_Info(CYPDF_TRUE, pdf->curr_ID++, "Test", "Pieter", "Test", "CyPDF", "CyProducer", creation_date);
        free(creation_date);

        pdf->obj_list = CYPDF_New_List();
        CYPDF_List_Append(pdf->obj_list, pdf->catalog);
        CYPDF_List_Append(pdf->obj_list, pdf->page_tree);
        CYPDF_List_Append(pdf->obj_list, pdf->info);
    }

    return pdf;
}

void CYPDF_Append_Page(CYPDF_Doc* pdf) {
    CYPDF_Obj_Page* page = CYPDF_Add_Page(pdf->page_tree, pdf->curr_ID++, CYPDF_A4_MEDIABOX);
    CYPDF_List_Append(pdf->obj_list, page);
}

void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf, const char* file_path) {
    if (fp == NULL || pdf == NULL) {
        return;
    }

    CYPDF_Write_File_Header(fp, pdf->file_header);

    CYPDF_Obj_List* list = pdf->obj_list;
    pdf->offsets = CYPDF_smalloc(list->count * sizeof(CYPDF_INT64));
    for (size_t i = 0; i < list->count; ++i) {
        pdf->offsets[i] = ftell(fp);
        CYPDF_Write_Obj_Def(fp, list->objects[i]);
    }

    CYPDF_INT64 xref_offset = ftell(fp);
    CYPDF_Write_Xref(fp, pdf);
    CYPDF_Write_Trailer(fp, pdf, file_path, xref_offset);
}

void CYPDF_Free_Doc(CYPDF_Doc* pdf) {
    if (pdf) {
        CYPDF_Free_File_Header(pdf->file_header);

        CYPDF_Obj_List* list = pdf->obj_list;
        for (size_t i = 0; i < list->count; ++i) {
            CYPDF_Free_Obj(list->objects[i], CYPDF_TRUE);
        }

        free(pdf);
    }
}