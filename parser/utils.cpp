#include "utils.h"

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
