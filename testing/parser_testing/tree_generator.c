void find_first_layer(char** tokens){

    char* opening_delimiters = "\\{(";

    int i = 0;
    while (tokens[i] != NULL){
        if (strchr(opening_delimiters, tokens[i][0])){
            printf("%d\n",i);
        }
        i++;
    }
}

void generate_tree(char** tokens){
    find_first_layer(tokens);
}