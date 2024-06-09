#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 16384

void print_tokens_by_index(char** tokens,int* indeces_array){
    int i = 0;
    while(indeces_array[i+1] != 0){
        printf("%s , ",tokens[indeces_array[i]]);
        i++;
    }
    printf("%s\n",tokens[indeces_array[i]]);
}

// This function returns all indices of tokens within the first layer
void find_first_layer_indices(char** tokens,int* indeces_array){

    int indeces_array_length = 0;

    char* single_delimiters = "\\";
    char* opening_delimiters = "{(;";
    char* closing_delimiters = "});";


    int depth = 0;
    bool first_layer = true;
    char* last_upper_layer_token;

    int i = 0;
    while (tokens[i] != NULL){

        if (first_layer == true){
            if (!strchr(single_delimiters, tokens[i-1][0])){
                // printf("%s ",tokens[i]);
                indeces_array[indeces_array_length] = i;
                indeces_array_length++;
            }
        }


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

        i++;
    }
}

void generate_tree(char** tokens){
    int indeces_array[MAX_TOKENS];
    find_first_layer_indices(tokens,indeces_array);
    print_tokens_by_index(tokens,indeces_array);
}