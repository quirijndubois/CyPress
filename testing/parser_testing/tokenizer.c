// Implmentation of tokenizer.py in c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 16384
#define MAX_TOKEN_LENGTH 2024

// Function to replace all occurrences of a substring with another string
char* replace_substring(const char* str, const char* old, const char* new_str) {
    char* result;
    int i, cnt = 0;
    int new_len = strlen(new_str);
    int old_len = strlen(old);

    // Count the number of times old substring occurs in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], old) == &str[i]) {
            cnt++;
            i += old_len - 1;
        }
    }

    // Allocating space for the new result
    result = (char*)malloc(i + cnt * (new_len - old_len) + 1);

    i = 0;
    while (*str) {
        if (strstr(str, old) == str) {
            strcpy(&result[i], new_str);
            i += new_len;
            str += old_len;
        } else {
            result[i++] = *str++;
        }
    }
    result[i] = '\0';
    return result;
}

// Function to strip syntax from the input string
char* syntax_stripper(const char* syntax_string) {
    char* stripped_syntax_string = (char*)malloc(2 * strlen(syntax_string) + 1); // Allocate more space for escape characters

    strcpy(stripped_syntax_string, syntax_string);

    // Replace \n with \\newline
    char* temp_str = replace_substring(stripped_syntax_string, "\n", " \\newline ");
    free(stripped_syntax_string);
    stripped_syntax_string = temp_str;

    // Remove multiple spaces
    char* result = (char*)malloc(strlen(stripped_syntax_string) + 1);

    int i, j = 0;
    int in_space = 0;
    for (i = 0; stripped_syntax_string[i] != '\0'; i++) {
        if (isspace(stripped_syntax_string[i])) {
            if (!in_space) {
                result[j++] = ' ';
                in_space = 1;
            }
        } else {
            result[j++] = stripped_syntax_string[i];
            in_space = 0;
        }
    }
    result[j] = '\0';

    free(stripped_syntax_string);
    return result;
}

// Function to separate the syntax string into tokens
void separate(const char* syntax_string, char** tokens, int* token_count) {
    const char* delimiters = "()\\;\",";
    char current_token[MAX_TOKEN_LENGTH];
    int current_token_index = 0;
    int i;

    *token_count = 0;

    for (i = 0; syntax_string[i] != '\0'; i++) {
        char c = syntax_string[i];

        if (c == ' ') {
            if (current_token_index != 0) {
                current_token[current_token_index] = '\0';
                tokens[*token_count] = strdup(current_token);
                (*token_count)++;
                current_token_index = 0;
            }
        } else if (strchr(delimiters, c)) {
            if (current_token_index != 0) {
                current_token[current_token_index] = '\0';
                tokens[*token_count] = strdup(current_token);
                (*token_count)++;
                current_token_index = 0;
            }
            current_token[0] = c;
            current_token[1] = '\0';
            tokens[*token_count] = strdup(current_token);
            (*token_count)++;
        } else {
            current_token[current_token_index++] = c;
        }
    }

    if (current_token_index != 0) {
        current_token[current_token_index] = '\0';
        tokens[*token_count] = strdup(current_token);
        (*token_count)++;
    }
}

void tokenize_string(const char* syntax_string, char** tokens, int* token_count) {
    char* stripped_syntax_string = syntax_stripper(syntax_string);
    separate(stripped_syntax_string, tokens, token_count);
    free(stripped_syntax_string);
}



int tokenize_file(char* path,char** tokens){
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* syntax_string = (char*)malloc(fsize + 1);

    fread(syntax_string, 1, fsize, file);
    fclose(file);
    syntax_string[fsize] = '\0';

    int token_count;
    tokenize_string(syntax_string, tokens, &token_count);

    free(syntax_string);
    return 0;
}
