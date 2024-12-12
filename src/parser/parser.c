#include "parser.h"

void combine_command_tokens(char **tokens, char **combined_tokens)
{
    // this function iterates over all tokens
    // and combine every backslash with the following token

    int i = 0; // Token index
    int j = 0; // Combined token index
    while (tokens[i] != NULL)
    {
        char *token = tokens[i];
        char first_char = token[0];
        int token_length = strlen(token);

        if (first_char == '\\' && token_length == 1)
        {
            char *next_token = tokens[i + 1];
            // we combine '\\' with the next token, so we get next_token="\\oldtoken"
            char *next_token_with_old_token = malloc(strlen(next_token) + strlen(token) + 1);
            strcpy(next_token_with_old_token, token);
            strcat(next_token_with_old_token, next_token);

            combined_tokens[j] = next_token_with_old_token;
            i += 2;
            j++;
        }
        else
        {
            combined_tokens[j] = token;
            i++;
            j++;
        }
    }
    combined_tokens[i] = NULL;
}

void combine_tokens(char **tokens, char **combined_tokens)
{
    combine_command_tokens(tokens, combined_tokens);
}

void parse(char *path)
{
    char *tokens[MAX_TOKENS];
    char *combined_tokens[MAX_TOKENS];

    tokenize_file(path, tokens);
    combine_tokens(tokens, combined_tokens);
    print_tokens(combined_tokens);
    generate_tree(tokens);
}
