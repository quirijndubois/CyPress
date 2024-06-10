#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define ANSI color codes
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define NORMAL_GREEN "\033[32m"
#define DARK_GREEN "\033[32;2m"
#define BROWN "\x1b[31m"
#define DARK_BROWN "\x1b[31;2m"
#define BLUE "\x1b[34m"

void print_tokens(char** tokens){
    int i = 0;
    while (tokens[i+1]!=NULL) {
        printf("'%s',", tokens[i]);
        i++;
    }
    printf("'%s'\n", tokens[i]);
}

void print_tokens_by_index(char** tokens,int* indeces_array){
    int i = 0;
    while(indeces_array[i+1] != 0){
        printf("%s , ",tokens[indeces_array[i]]);
        i++;
    }
    printf("%s\n",tokens[indeces_array[i]]);
}

void print_tokens_index(char** tokens){
    int i = 0;
    while (tokens[i+1]!=NULL) {
        printf("%d  %s\n",i, tokens[i]);
        i++;
    }
    printf("%d  %s\n",i, tokens[i]);
}

void print_logo() {
    const char* dark_green_chars = "*";
    const char* normal_green_chars = ".+=";
    const char* brown_chars = ";";
    const char* dark_brown_chars = ">#";
    const char* blue_chars = "/|_-()\\,\'";

    char* filename = "logo.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (strchr(dark_green_chars, line[i])) {
                printf(DARK_GREEN "%c" RESET, line[i]);
            } else if (strchr(normal_green_chars, line[i])) {
                printf(NORMAL_GREEN "%c" RESET, line[i]);
            } else if (strchr(brown_chars, line[i])) {
                printf(BROWN "%c" RESET, line[i]);
            } else if (strchr(dark_brown_chars, line[i])) {
                printf(DARK_BROWN "%c" RESET, line[i]);
            } else if (strchr(blue_chars, line[i])) {
                printf(BLUE "%c" RESET, line[i]);
            } else {
                printf("%c", line[i]);  // Default color
            }
        }
    }

    fclose(file);
    printf("\n");
}

