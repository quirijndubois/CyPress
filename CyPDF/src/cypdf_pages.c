#include <stdio.h>
#include <stdlib.h>

#include "cypdf_pages.h"
#include "cypdf_array.h"
#include "cypdf_consts.h"
#include "cypdf_dict.h"
#include "cypdf_name.h"
#include "cypdf_number.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



CYPDF_Obj_Page* CYPDF_New_Page(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* parent, CYPDF_Rect mediabox) {
    CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_PAGE, ID);
    if (page) {
        page->parent = parent;
        page->resources = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        page->mediabox = CYPDF_Array_From_Rect(mediabox, CYPDF_FALSE, CYPDF_DEFAULT_OID);

        page->dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        if (page->dict) {
            /* The type of the PDF object that this dictionary describes. */
            CYPDF_Obj_Name* type = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OID, "Page");
            CYPDF_Dict_Append(page->dict, CYPDF_TYPE_NAME, type);

            /* The rest of the dictionary will be build only when this page_node is printed. */
        }
    }

    return page;
}

CYPDF_Obj_PNode* CYPDF_New_PNode(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* parent) {
    CYPDF_Obj_PNode* page_node = (CYPDF_Obj_PNode*)CYPDF_New_Obj(indirect, CYPDF_OCLASS_PNODE, ID);
    if (page_node) {
        page_node->parent = parent;
        page_node->kids = CYPDF_New_Array(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        page_node->leaf_count = 0;

        page_node->dict = CYPDF_New_Dict(CYPDF_FALSE, CYPDF_DEFAULT_OID);
        if (page_node->dict) {
            /* The type of the PDF object that this dictionary describes. */
            CYPDF_Obj_Name* type = CYPDF_New_Name(CYPDF_FALSE, CYPDF_DEFAULT_OGEN, "Pages");
            CYPDF_Dict_Append(page_node->dict, CYPDF_TYPE_NAME, type);

            /* The rest of the dictionary will be build only when this page_node is printed. */
        }
    }

    return page_node;
}

CYPDF_Obj_Page* CYPDF_Add_Page(CYPDF_Obj_PNode* page_tree, CYPDF_UINT32 ID, CYPDF_Rect mediabox) {
    CYPDF_Obj_Page* page = CYPDF_New_Page(CYPDF_TRUE, ID, page_tree, mediabox);

    if (page) {
        CYPDF_Array_Append(page_tree->kids, page);
        ++page_tree->leaf_count;
    }

    return page;
}

void CYPDF_Write_Page(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)obj;

    CYPDF_Dict_Append(page->dict, "Parent", page->parent);
    if (page->resources->count) {
        CYPDF_Dict_Append(page->dict, "Resources", page->resources); /* If no resources are present, they are inherited from parent. */
    }
    CYPDF_Dict_Append(page->dict, "MediaBox", page->mediabox);

    CYPDF_Write_Obj_Direct(fp, page->dict);
}

void CYPDF_Write_PNode(FILE* fp, CYPDF_Object* obj) {
    if (fp == NULL || obj == NULL) {
        return;
    }

    CYPDF_Obj_PNode* page_node = (CYPDF_Obj_PNode*)obj;

    if (page_node->parent) {
        CYPDF_Dict_Append(page_node->dict, "Parent", page_node->parent);
    }
    CYPDF_Dict_Append(page_node->dict, "Kids", page_node->kids);
    CYPDF_Obj_Number* leaf_count = CYPDF_New_Number(CYPDF_FALSE, CYPDF_DEFAULT_OID, page_node->leaf_count);
    CYPDF_Dict_Append(page_node->dict, "Count", leaf_count);

    CYPDF_Write_Obj_Direct(fp, page_node->dict);
}

void CYPDF_Free_Page(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_Page* page = (CYPDF_Obj_Page*)obj;
    
        CYPDF_Free_Obj(page->parent, CYPDF_FALSE);
        CYPDF_Free_Obj(page->resources, CYPDF_FALSE);
        CYPDF_Free_Obj(page->mediabox, CYPDF_FALSE);
        CYPDF_Free_Obj(page->dict, CYPDF_FALSE);

        free(page);
    }
}

void CYPDF_Free_PNode(CYPDF_Object* obj) {
    if (obj) {
        CYPDF_Obj_PNode* page_node = (CYPDF_Obj_PNode*)obj;

        CYPDF_Free_Obj(page_node->parent, CYPDF_FALSE);
        CYPDF_Free_Obj(page_node->kids, CYPDF_FALSE);
        CYPDF_Free_Obj(page_node->dict, CYPDF_FALSE);

        free(page_node);
    }
}