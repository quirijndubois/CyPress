#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "utils.c"

#define MAX_TOKENS 16384

#define SINGLE_DELIMITERS "\\"
#define OPENING_DELIMITERS "{("
#define CLOSING_DELIMITERS "})"
#define DOUBLE_DELIMITERS ";\"\'"


int get_tokens_length(char** tokens){
    int i = 0;
    while (tokens[i] != NULL){
        i++;
    }
    return i;
}

// This function returns all indices of tokens within the first layer
void find_first_layer_indices(char** tokens,int* indeces_array,int start_index, int ending_index){

    int indeces_array_length = 0;

    int depth = 0;
    bool first_layer = true;
    char* last_upper_layer_token;

    bool inside_double_delimiter = false;

    int i = start_index;
    while (i < ending_index){

        if (first_layer == true){
            if (!strchr(SINGLE_DELIMITERS, tokens[i-1][0])){
                indeces_array[indeces_array_length] = i;
                indeces_array_length++;
            }
        }


        if (strchr(OPENING_DELIMITERS, tokens[i][0])){
            first_layer = false;
            depth++;
        }
        else if (strchr(CLOSING_DELIMITERS, tokens[i][0])){
            depth--;
            if (depth == 0){
                first_layer = true;
            }
        }
        else if (strchr(DOUBLE_DELIMITERS, tokens[i][0])){
            if(!inside_double_delimiter){
                inside_double_delimiter = true;
                first_layer = false;
                depth++;
            }
            else{
                depth--;
                inside_double_delimiter = false;
                if (depth == 0){
                    first_layer = true;
                }
            }
        }

        i++;
    }

}
int get_layer_end(char** tokens, int starting_index){


    if(strchr(SINGLE_DELIMITERS, tokens[starting_index][0])){
        return starting_index+1;
    }
    else if(strchr(OPENING_DELIMITERS, tokens[starting_index][0])){

        int depth = 0;
        bool stop = false;
        int i = starting_index+1;
        while(stop == false){
            if(strchr(OPENING_DELIMITERS, tokens[i][0])){
                depth++;
            }
            else if(strchr(CLOSING_DELIMITERS, tokens[i][0])){
                if (depth == 0){
                    stop = true;
                }
                depth--;
            }
            i++;
        }
        return i-2;
    }
    else if(strchr(DOUBLE_DELIMITERS, tokens[starting_index][0])){


        int depth = 0;
        bool stop = false;
        int i = starting_index+1;
        while(stop == false){
            if(tokens[starting_index][0] == tokens[i][0]){
                stop = true;
            }
            i++;
        }
        return i-2;
    }


    return starting_index;
}

void recursive_layer_generator(char **tokens,int start_index, int ending_index){

    int indeces_array[MAX_TOKENS];
    find_first_layer_indices(tokens,indeces_array,start_index,ending_index);
    // print_tokens_by_index(tokens,indeces_array);
}

void generate_tree(char** tokens){

    // print_tokens_index(tokens);

    recursive_layer_generator(tokens,0,get_tokens_length(tokens));

}