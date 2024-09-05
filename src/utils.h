// Define ANSI color codes
#include <stdio.h>
#include <string.h>
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define NORMAL_GREEN "\033[32m"
#define DARK_GREEN "\033[32;2m"
#define BROWN "\x1b[31m"
#define DARK_BROWN "\x1b[31;2m"
#define BLUE "\x1b[34m"

void print_logo() {
    const char* dark_green_chars = "*";
    const char* normal_green_chars = ".+=";
    const char* brown_chars = ";";
    const char* dark_brown_chars = ">#";
    const char* blue_chars = "/|_-()\\,\'";

    char* filename = "logo.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (strchr(dark_green_chars, line[i])) {
                printf(DARK_GREEN "%c" RESET, line[i]);
            } else if (strchr(normal_green_chars, line[i])) {
                printf(NORMAL_GREEN "%c" RESET, line[i]);
            } else if (strchr(brown_chars, line[i])) {
                printf(BROWN "%c" RESET, line[i]);
            } else if (strchr(dark_brown_chars, line[i])) {
                printf(DARK_BROWN "%c" RESET, line[i]);
            } else if (strchr(blue_chars, line[i])) {
                printf(BLUE "%c" RESET, line[i]);
            } else {
                printf("%c", line[i]);  // Default color
            }
        }
    }

    fclose(file);
    printf("\n");
}

