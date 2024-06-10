#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.c"
#include "tree_generator.c"



int main() {
    char* tokens[MAX_TOKENS];
    char* path = "example.cyp";
    tokenize_file(path,tokens);
    // print_tokens(tokens);
    generate_tree(tokens);
    print_logo();
}