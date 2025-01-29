#include "tree_generator.h"
#include <stdbool.h>
#include <stdio.h>

// define the delimiters
#define SINGLE_DELIMITERS "\\"
#define OPENING_DELIMITERS "{("
#define CLOSING_DELIMITERS "})"
#define DOUBLE_DELIMITERS ";\"\'"

int get_tokens_length(char **tokens)
{
    int i = 0;
    while (tokens[i] != NULL)
    {
        i++;
    }
    return i;
}

int get_next_token_in_layer(char **tokens, int starting_index)
{

    if (strchr(OPENING_DELIMITERS, tokens[starting_index][0]))
    {
        int depth = 0;
        bool stop = false;
        int i = starting_index + 1;
        while (stop == false)
        {
            if (strchr(OPENING_DELIMITERS, tokens[i][0]))
            {
                depth++;
            }
            else if (strchr(CLOSING_DELIMITERS, tokens[i][0]))
            {
                if (depth == 0)
                {
                    stop = true;
                }
                depth--;
            }
            i++;
        }
        return i - 2;
    }
    // else if (strchr(DOUBLE_DELIMITERS, tokens[starting_index][0]))
    // {
    //     int depth = 0;
    //     bool stop = false;
    //     int i = starting_index + 1;
    //     while (stop == false)
    //     {
    //         if (tokens[starting_index][0] == tokens[i][0])
    //         {
    //             stop = true;
    //         }
    //         i++;
    //     }
    //     return i - 2;
    // }
    return starting_index;
}

// void find_first_layer_indices(char **tokens, int *indeces_array, int start_index, int ending_index)
// {
//     int indeces_array_length = 0;

//     int i = start_index;
//     while (start_index <= ending_index)
//     {
//     }
// }

void generate_tree(char **tokens)
{
    // print layer end for each token
    int i = 0;
    int len = get_tokens_length(tokens);

    // printf("%d -> %d\n", 15, get_next_token_in_layer(tokens, 15));

    for (i = 0; i < len; i++)
    {
        printf("%d -> %d\n", i, get_next_token_in_layer(tokens, i));
    }
}
