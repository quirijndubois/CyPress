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
#include "cypdf_page.h"
#include "cypdf_pages.h"
#include "cypdf_utils.h"



static void CYPDF_Add_Page_Root(CYPDF_Doc* pdf_doc) {
    ++pdf_doc->obj_count;
    CYPDF_Obj_Pages* pages = CYPDF_New_Pages(CYPDF_TRUE, pdf_doc->obj_count, NULL);
    if (pages) {
        pdf_doc->page_root = pages;
    }
}

static void CYPDF_Add_Catalog(CYPDF_Doc* pdf_doc, CYPDF_Obj_Pages* page_root) {
    ++pdf_doc->obj_count;
    CYPDF_Obj_Catalog* catalog = CYPDF_New_Catalog(CYPDF_TRUE, pdf_doc->obj_count, page_root);
    if (catalog) {
        pdf_doc->catalog = catalog;
    }
}

CYPDF_Doc* CYPDF_New_Doc() {
    CYPDF_Doc* pdf_doc = CYPDF_smalloc(sizeof(CYPDF_Doc));
    if (pdf_doc) {
        pdf_doc->file_header = CYPDF_New_File_Header();

        CYPDF_Add_Page_Root(pdf_doc);
        CYPDF_Add_Catalog(pdf_doc, pdf_doc->page_root);

        pdf_doc->obj_list = CYPDF_New_List(CYPDF_Free_Obj);
    }

    return pdf_doc;
}

void CYPDF_Add_Page(CYPDF_Doc* pdf_doc, CYPDF_Rect size) {
    ++pdf_doc->obj_count;
    CYPDF_Obj_Page* page = CYPDF_New_Page(CYPDF_TRUE, pdf_doc->obj_count, pdf_doc->page_root, size);
    if (page) {
        CYPDF_List_Append(((CYPDF_Obj_Array*)((CYPDF_Dict_Entry*)pdf_doc->page_root->dict->entry_list->elements[1])->value_obj)->obj_list, page);
        ((CYPDF_Dict_Entry*)page->dict->entry_list->elements[1])->value_obj = pdf_doc->page_root;
        CYPDF_List_Append(pdf_doc->obj_list, page);
    }
}

void CYPDF_Write_Doc(FILE* fp, CYPDF_Doc* pdf_doc) {
    if (fp == NULL || pdf_doc == NULL) {
        return;
    }

    CYPDF_Write_File_Header(fp, pdf_doc->file_header);
    CYPDF_Write_Obj_Def(fp, pdf_doc->catalog);
    CYPDF_Write_Obj_Def(fp, pdf_doc->page_root);

    for (size_t i = 1; i < pdf_doc->obj_count; ++i) {
        CYPDF_Write_Obj_Def(fp, pdf_doc->obj_list->elements[i]);
    }
}

void CYPDF_Free_Doc(CYPDF_Doc* pdf_doc) {
    if (pdf_doc) {
        CYPDF_Free_File_Header(pdf_doc->file_header);
        CYPDF_Free_Obj(pdf_doc->catalog, CYPDF_TRUE);
        CYPDF_Free_Obj(pdf_doc->page_root, CYPDF_TRUE);

        for (size_t i = 1; i < pdf_doc->obj_count; ++i) {
            CYPDF_Free_Obj(pdf_doc->obj_list->elements, CYPDF_TRUE);
        }

        free(pdf_doc);
    }
}