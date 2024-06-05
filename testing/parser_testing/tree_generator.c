void generate_tree(char** tokens){
    // Not implemented! 
    // Right now just printing the tokens
    int i = 0;
    while (tokens[i]!=NULL) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
        i++;
    }
}