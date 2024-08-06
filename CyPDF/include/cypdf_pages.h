#ifndef CYPDF_PAGES_H
#define CYPDF_PAGES_H


#include "cypdf_array.h"
#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_PAGE                    CYPDF_Write_Page
#define CYPDF_FREE_PAGE                     CYPDF_Free_Page

#define CYPDF_WRITE_PNODE                   CYPDF_Write_PNode
#define CYPDF_FREE_PNODE                    CYPDF_Free_PNode


typedef struct _CYPDF_Obj_Page_Node CYPDF_Obj_PNode;

/* CYPDF_Obj_Page struct */
typedef struct _CYPDF_Obj_Page {
    CYPDF_Obj_Header        header;

    CYPDF_Obj_PNode*        parent;
    CYPDF_Obj_Dict*         resources;
    CYPDF_Obj_Array*        mediabox;

    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_Page;


/* CYPDF_Obj_PNode struct */
typedef struct _CYPDF_Obj_Page_Node {
    CYPDF_Obj_Header        header;

    CYPDF_Obj_PNode*        parent;
    CYPDF_Obj_Array*        kids;
    CYPDF_INT               leaf_count; /* The number of leaf nodes (page objects) that are descendants of this node within the page tree. */

    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_PNode;


/**
 * @brief Creates new CYPDF_Obj_Page.
 * 
 * @param indirect 
 * @param ID 
 * @param parent 
 * @param mediabox 
 * @return CYPDF_Obj_Page* | Returns NULL if object creation fails.
 */
CYPDF_Obj_Page* CYPDF_New_Page(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* parent, CYPDF_Rect mediabox);

/**
 * @brief Creates new CYPDF_Obj_PNode.
 * 
 * @param indirect 
 * @param ID 
 * @param parent 
 * @return CYPDF_Obj_PNode* | Returns NULL if object creation fails.
 */
CYPDF_Obj_PNode* CYPDF_New_PNode(CYPDF_BOOL indirect, CYPDF_UINT32 ID, CYPDF_Obj_PNode* parent);

/**
 * @brief Adds a new page to page_tree.
 * 
 * @param tree_root 
 * @param ID 
 * @param mediabox 
 */
CYPDF_Obj_Page* CYPDF_Add_Page(CYPDF_Obj_PNode* page_tree, CYPDF_UINT32 ID, CYPDF_Rect mediabox);

/**
 * @brief Writes obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Page(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Write obj to fp. Does nothing if fp == NULL or obj == NULL.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_PNode(FILE* fp, CYPDF_Object* obj);


/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_Page(CYPDF_Object* obj);

/**
 * @brief Frees obj. Does nothing if obj is NULL.
 * 
 * @param obj 
 */
void CYPDF_Free_PNode(CYPDF_Object* obj);



#endif /* CYPDF_PAGES_H */