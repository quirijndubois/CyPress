#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define ANSI color codes
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

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
    char* filename = "logo.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    // int color_counter = 0;

    printf(GREEN);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    printf(RESET); // Reset color
    fclose(file);
    printf("\n");
}