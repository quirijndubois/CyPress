#include "parser.h"

void parse(char* path) {
    
    char* tokens[MAX_TOKENS];
    tokenize_file(path,tokens);
    print_tokens(tokens);
    generate_tree(tokens);
}
