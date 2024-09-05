#include <stddef.h>
#include <string.h>

#define MAX_TOKENS 16384

#define SINGLE_DELIMITERS "\\"
#define OPENING_DELIMITERS "{("
#define CLOSING_DELIMITERS "})"
#define DOUBLE_DELIMITERS ";\"\'"

int get_tokens_length(char** tokens);

// This function returns all indices of tokens within the first layer
void find_first_layer_indices(char** tokens,int* indeces_array,int start_index, int ending_index);

int get_layer_end(char** tokens, int starting_index);

void recursive_layer_generator(char **tokens,int start_index, int ending_index);

void generate_tree(char** tokens);
