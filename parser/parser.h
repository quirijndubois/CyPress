#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "tree_generator.h"
#include "utils.h"

void parse(char* path) {
    
    char* tokens[MAX_TOKENS];
    tokenize_file(path,tokens);
    print_tokens(tokens);
    generate_tree(tokens);
}