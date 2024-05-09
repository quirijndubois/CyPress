#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pdf.h"

enum OBJType {
    OBJ_null,
    OBJ_catalog,
    OBJ_info,
    OBJ_page_leaf,
    OBJ_page_root,

    OBJ_count,
};

struct object_array {
    int object_count;
    int array_size;
    struct PDF_object** objects;
};

struct PDF_object_page_leaf {
    struct PDF_object* parent;
};

struct PDF_object {
    int type;
    int object_num;
    long long offset; // Byte offset.

    struct PDF_object* prev; // Next object of this type.
    struct PDF_object* next; // Previous object of this type.

    union {
        struct PDF_info info;
        struct PDF_object_page_leaf;
    };
};

struct PDF_doc {
    struct object_array* objects;

    struct PDF_object* last_objects[OBJ_count];
    struct PDF_object* first_objects[OBJ_count];
};


static int pdf_object_array_append(struct object_array* array, struct PDF_object* object) {
    ++array->object_count;
    if (array->object_count == array->array_size + 1) {
        if (!array->array_size) {
            array->array_size = 1;
        } else {
            array->array_size *= 2;
        }
        array->objects = realloc(array->objects, (size_t)abs(array->array_size) * sizeof(struct PDF_object*));
    }

    array->objects[array->object_count - 1] = object;

    return array->object_count - 1;
}

static int pdf_object_array_size(struct object_array* array) {
    return array->object_count;
}

static struct PDF_object* pdf_object_array_at_index(struct object_array* array, int index) {
    return array->objects[index];
}

static struct PDF_object* pdf_get_first_object(struct PDF_doc* pdf, int type) {
    return pdf->first_objects[type];
}

// static struct PDF_object* pdf_get_last_object(struct PDF_doc* pdf, int type) {
//     return pdf->last_objects[type];
// }

static char* pdf_create_date() {
    char* date = calloc(128, sizeof(char));
    time_t currtime = time(NULL);
    time_t UTC = mktime(gmtime(&currtime));
    struct tm* local = localtime(&currtime);

    char relationship = '+';
    int diff_seconds = (int)difftime(mktime(local), UTC);
    if (diff_seconds < 0) {
        relationship = '-';
    } else if (diff_seconds == 0) {
        relationship = 'Z';
    }
    int diff_hours = diff_seconds / 3600;
    int diff_minutes = (diff_seconds - diff_hours * 3600) / 60;

    sprintf(date, "D:%04d%02d%02d%02d%02d%02d%c%02d\'%02d\'", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec, relationship, diff_hours, diff_minutes);

    return date;
}

struct PDF_info* pdf_create_info(const char* title, const char* author, const char* subject, const char* creator, const char* producer) {
    struct PDF_info* info = calloc(1, sizeof(struct PDF_info));
    if (title) {
        sprintf_s(info->title, INFO_CHAR_LIMIT, "%s", title);
    }
    if (author) {
        sprintf_s(info->author, INFO_CHAR_LIMIT, "%s", author);
    }
    if (subject) {
        sprintf_s(info->subject, INFO_CHAR_LIMIT, "%s", subject);
    }
    if (creator) {
        sprintf_s(info->creator, INFO_CHAR_LIMIT, "%s", creator);
    }
    if (producer) {
        sprintf_s(info->producer, INFO_CHAR_LIMIT, "%s", producer);
    }

    char* date = pdf_create_date();
    if (date) {
        sprintf_s(info->creation_date, INFO_CHAR_LIMIT, "%s", date);
    }
    free(date);

    return info;
}

static void pdf_append_object(struct PDF_doc* pdf, struct PDF_object* object) {
    int index = pdf_object_array_append(pdf->objects, object);
    object->object_num = index;

    if (pdf->last_objects[object->type]) {
        object->prev = pdf->last_objects[object->type];
        pdf->last_objects[object->type]->next = object;
    }
    pdf->last_objects[object->type] = object;

    if (!pdf->first_objects[object->type]) {
        pdf->first_objects[object->type] = object;
    }
}

static struct PDF_object* pdf_add_object(struct PDF_doc* pdf, int type) {
    struct PDF_object* object = calloc(1, sizeof(struct PDF_object));
    object->type = type;
    
    pdf_append_object(pdf, object);

    return object;
}

static struct PDF_object* pdf_add_info(struct PDF_doc* pdf, struct PDF_info* info) {
    struct PDF_object* info_object = pdf_add_object(pdf, OBJ_info);

    memcpy(&info_object->info, info, sizeof(struct PDF_info));
    
    return info_object;
}

static struct PDF_object* pdf_add_catalog(struct PDF_doc* pdf) {
    struct PDF_object* catalog = pdf_add_object(pdf, OBJ_catalog);

    return catalog;
}

static struct PDF_object* pdf_add_page_root(struct PDF_doc* pdf) {
    struct PDF_object* page_root = pdf_add_object(pdf, OBJ_page_root);

    return page_root;
}

struct PDF_doc* pdf_create(struct PDF_info* info) {
    struct PDF_doc* pdf = calloc(1, sizeof(struct PDF_doc));
    pdf->objects = calloc(1, sizeof(struct object_array));
    
    // Object indexing should start at 1.
    pdf_add_object(pdf, OBJ_null);

    pdf_add_info(pdf, info);

    pdf_add_page_root(pdf);

    pdf_add_catalog(pdf);

    return pdf;
}

static void pdf_construct_catalog(FILE* fp, struct PDF_doc* pdf) {
    // Begin dictionary.
    fprintf(fp, "<<\n");

    // Type entry, this object describes a catalog.
    fprintf(fp, "/Type /Catalog\n");

    // Page entry.
    struct PDF_object* page_root = pdf_get_first_object(pdf, OBJ_page_root);
    fprintf(fp, "/Pages %d 0 R\n", page_root->object_num);

    // End dictionary.
    fprintf(fp, ">>\n");
}

static void pdf_construct_info(FILE* fp, struct PDF_object* info) {
    // Begin dictionary.
    fprintf(fp, "<<\n");

    if (info->info.title[0]) {
        fprintf(fp, "/Title (%s)\n", info->info.title);
    }
    if (info->info.author[0]) {
        fprintf(fp, "/Author (%s)\n", info->info.author);
    }
    if (info->info.subject[0]) {
        fprintf(fp, "/Subject (%s)\n", info->info.subject);
    }
    if (info->info.creator[0]) {
        fprintf(fp, "/Creator (%s)\n", info->info.creator);
    }
    if (info->info.producer[0]) {
        fprintf(fp, "/Producer (%s)\n", info->info.producer);
    }
    if (info->info.creation_date[0]) {
        fprintf(fp, "/CreationDate (%s)\n", info->info.creation_date);
    }

    // End dictionary.
    fprintf(fp, ">>\n");
}

static void pdf_construct_page_root(FILE* fp, struct PDF_doc* pdf) {
    // Begin dictionary.
    fprintf(fp, "<<\n");

    // Type entry, this object describes a page tree root.
    fprintf(fp, "/Type /Pages\n");

    // Kids entry: an array of page references to all kids is constructed.
    fprintf(fp, "/Kids [");
    int chars_on_line = 7;
    char* reference = malloc(32 * sizeof(char)); // A reference is not expected to exceed a character count of 32.
    int reference_length = 0;
    struct PDF_object* current_kid = pdf_get_first_object(pdf, OBJ_page_leaf);
    int count = 0;
    while(current_kid) {
        if (!current_kid->next) {
            reference_length = sprintf(reference, "%d 0 R]", current_kid->object_num);
        } else {
            reference_length = sprintf(reference, "%d 0 R ", current_kid->object_num);
        }
        if (chars_on_line + reference_length > LINE_CHARACTER_LIMIT) {
            fprintf(fp, "\n");
            chars_on_line = 0;
        }
        fprintf(fp, "%s", reference);
        chars_on_line += reference_length;
        ++count;
    }
    fprintf(fp, "\n");
    free(reference);

    // Count entry: the amount of kids.
    fprintf(fp, "/Count %d\n", count);

    // End dictionary.
    fprintf(fp, ">>\n");
}

static void pdf_construct_object(FILE* fp, struct PDF_doc* pdf, int index) {
    struct PDF_object* object = pdf_object_array_at_index(pdf->objects, index);
    object->offset = ftell(fp);
    if (object->type == OBJ_null) {
        return;
    }

    // Start new object.
    fprintf(fp, "%d 0 object\n", object->object_num);

    // Write object contents.
    switch (object->type) {
        case OBJ_catalog:
            pdf_construct_catalog(fp, pdf);
            break;
        case OBJ_info:
            pdf_construct_info(fp, object);
            break;
        case OBJ_page_root:
            pdf_construct_page_root(fp, pdf);
            break;
        default:
            break;
    }

    // End object.
    fprintf(fp, "endobject\n");
}

static void pdf_construct(FILE* fp, struct PDF_doc* pdf) {
    // Write header.
    fprintf(fp, "%%PDF-%s\n", PDF_VERSION);
    fprintf(fp, "%%%s\n", HIGH_VAL_BYTES);

    // Construct all objects.
    for(int i = 0; i < pdf_object_array_size(pdf->objects); ++i) {
        pdf_construct_object(fp, pdf, i);
    }

    // Write trailer.
    fprintf(fp, "%%%%EOF\n");
}

void pdf_save(const char* name, const char* dest, struct PDF_doc* pdf) {
    FILE* fp;
    if (!name) {
        fp = stdout;
    } else {
        char* file_path; // 6 is added to account for the '\' character between destination_path and document_name, the ".pdf" extension and the '\0' character.
        if (dest) {
            file_path = calloc((strlen(dest) + strlen(name) + 6), sizeof(char));
            sprintf(file_path, "%s\\%s.txt", dest, name);
        } else {
            file_path = calloc((strlen(name) + 6), sizeof(char));
            sprintf(file_path, "%s.txt", name);
        }
        fp = fopen(file_path, "wb"); // The file is written in binary since pdf requires byte values which can be misinterpreted as characters.
        free(file_path);
    }
    pdf_construct(fp, pdf);

    fclose(fp);
}