// Implementation of tokenizer.py in c

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_TOKENS 16384
#define MAX_TOKEN_LENGTH 2024

#define DELIMITERS "()\\;\"\',"

// Function to replace all occurrences of a substring with another string
char* replace_substring(const char* str, const char* old, const char* new_str);

// Function to strip syntax from the input string
char* syntax_stripper(const char* syntax_string);

// Function to separate the syntax string into tokens
void separate(const char* syntax_string, char** tokens, int* token_count);

void tokenize_string(const char* syntax_string, char** tokens, int* token_count);

int tokenize_file(char* path,char** tokens);
