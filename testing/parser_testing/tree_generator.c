#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void find_first_layer(char** tokens){

    char* single_delimiters = "\\";
    char* opening_delimiters = "{(";
    char* closing_delimiters = "})";

    int i = 0;

    int depth = 0;

    bool first_layer = true;

    while (tokens[i] != NULL){
        if (strchr(opening_delimiters, tokens[i][0])){
            first_layer = false;
            depth++;
        }
        else if (strchr(closing_delimiters, tokens[i][0])){
            depth=depth-1;
            if (depth == 0){
                first_layer = true;
            }
        }
        else if (strchr(single_delimiters, tokens[i-1][0])){
            // first_layer = false;
        }

        if (first_layer == true){
            printf("%s ",tokens[i]);
        }
        i++;
    }
}

void generate_tree(char** tokens){
    find_first_layer(tokens);
}