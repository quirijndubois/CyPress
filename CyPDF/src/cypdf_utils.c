#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cypdf_utils.h"
#include "cypdf_types.h"



void* CYPDF_smalloc(size_t size) {
    void* mem = malloc(size);
    if (!mem) {
        fprintf(stderr, "Failed to allocate %zu bytes of memory.\n", size);
    }

    return mem;
}

void* CYPDF_scalloc(size_t element_count, size_t element_size) {
    void* mem = calloc(element_count, element_size);
    if (!mem) {
        fprintf(stderr, "Failed to allocate %zu bytes of memory.\n", element_count * element_size);
    }

    return mem;
}

void* CYPDF_srealloc(void* ptr, size_t size) {
    void* mem = realloc(ptr, size);
    if (mem == NULL) {
        fprintf(stderr, "Failed to reallocate %p to a size of %zu.\n", ptr, size);
    }

    return mem;
}

char* CYPDF_Get_Date() {
    char* date = CYPDF_scalloc(128, sizeof(char));
    time_t currtime = time(NULL);
    time_t UTC = mktime(gmtime(&currtime));
    struct tm* local = localtime(&currtime);

    char relationship = 'Z';
    int diff_seconds = (int)difftime(mktime(local), UTC);
    if (diff_seconds < 0) {
        relationship = '-';
    } else if (diff_seconds > 0) {
        relationship = '+';
    }
    int diff_hours = diff_seconds / 3600;
    int diff_minutes = (diff_seconds - diff_hours * 3600) / 60;

    sprintf(date, "D:%04d%02d%02d%02d%02d%02d%c%02d\'%02d\'", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec, relationship, diff_hours, diff_minutes);

    return date;
}
