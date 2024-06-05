void generate_tree(char** tokens){
    int i = 0;
    while (tokens[i]!=NULL) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
        i++;
    }
}