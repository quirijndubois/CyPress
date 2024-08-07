#ifndef CYPDF_INFO_H
#define CYPDF_INFO_H


#include "cypdf_dict.h"
#include "cypdf_object.h"
#include "cypdf_types.h"



#define CYPDF_WRITE_INFO                    CYPDF_Write_Info
#define CYPDF_FREE_INFO                     CYPDF_Free_Info


#define CYPDF_INFO_MAX_SIZE                 128


/* CYPDF_Obj_Info struct */
typedef struct _CYPDF_Obj_Info {
    CYPDF_Obj_Header        header;

    char                    title[CYPDF_INFO_MAX_SIZE];             /* The document’s title. */
    char                    author[CYPDF_INFO_MAX_SIZE];            /* The name of the person who created the document. */
    char                    subject[CYPDF_INFO_MAX_SIZE];           /* The subject of the document. */

    char                    creator[CYPDF_INFO_MAX_SIZE];           /* If the document was converted to PDF from another format, the name of the application (for example, VSCode) that created the original document from which it was converted. */
    char                    producer[CYPDF_INFO_MAX_SIZE];          /* If the document was converted to PDF from another format, the name of the application (for example, CyProducer) that converted it to PDF. */
    char                    creation_date[CYPDF_INFO_MAX_SIZE];     /* The date and time the document was created, in human-readable form. */

    CYPDF_Obj_Dict*         dict;
} CYPDF_Obj_Info;


/**
 * @brief Creates new CYPDF_Obj_Info.
 * 
 * @param indirect
 * @param ID
 * @param title The document’s title.
 * @param author The name of the person who created the document.
 * @param subject The subject of the document.
 * @param creator If the document was converted to PDF from another format, the name of the application (for example, CyPress Editor) that created the original document from which it was converted.
 * @param producer If the document was converted to PDF from another format, the name of the application (for example, CyProducer) that converted it to PDF.
 * @param creation_date The date and time the document was created, in human-readable form.
 * @return CYPDF_Obj_Info* 
 */
CYPDF_Obj_Info* CYPDF_New_Info(CYPDF_BOOL indirect, CYPDF_UINT32 ID, const char* title, const char* author, const char* subject, const char* creator, const char* producer, const char* creation_date);

/**
 * @brief Writes obj to fp.
 * 
 * @param fp 
 * @param obj 
 */
void CYPDF_Write_Info(FILE* fp, CYPDF_Object* obj);

/**
 * @brief Frees obj.
 * 
 * @param obj 
 */
void CYPDF_Free_Info(CYPDF_Object* obj);



#endif /* CYPDF_INFO_H */