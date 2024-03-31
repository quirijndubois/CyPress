#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// We define length for all our arrays and strings, maybe dynamically setting this would improve performance
#define MAX_LINES 512 // Maximum number of lines to read
#define MAX_LINE_LENGTH 2048 // Maximum length of each line
#define MAX_PATH_LENGTH 128 // Maximum length chars in path
#define MAX_ELEMENT_LENGTH 2048 // Maximum length chars in element 
#define MAX_ELEMENT_AMOUNT 64 // Maximum length chars in element 
// Element is always a subset of line so make sure it is <= max line length

// We use the file struct keep track of our different file attributes
struct File {
    FILE *filePtr;
    char path[MAX_PATH_LENGTH];
    char buffer[MAX_LINES];
    char *lines[MAX_LINES];
    int lineAmount;
};

// We devide all our lines in LineElements, 
// so that every part of the line can have a different type(like: text, formula, bold text, etc.)
struct LineElement{
    char type[4];
    char text[MAX_ELEMENT_LENGTH];
};

struct Line{
    struct LineElement lineElements[MAX_ELEMENT_AMOUNT];
};

struct Document{
    struct Line lines[MAX_LINES];
};


int printFile(struct File file){
    if(file.lines[0] == NULL){
        return 1;
    }
    for (int i = 0; i < file.lineAmount; i++) {
        printf("Line %d: %s", i + 1, file.lines[i]);
    }
    printf("\n");
    return 0;
}

struct File readFile(char path[],bool print){
    //We use File struct to keep track of all file info, handy for parallel parsing in the future
    //First we difene our file that has to bee parsed
    struct File file;
    strcpy(file.path,path);
    file.filePtr = fopen(file.path, "r");

    // Check if correctly opened
    if (file.filePtr == NULL) {
        printf("Error opening file\n");
    }

    int lineCount = 0;
    while (fgets(file.buffer, MAX_LINE_LENGTH, file.filePtr) != NULL && lineCount < MAX_LINES) {
        file.lines[lineCount] = malloc(strlen(file.buffer) + 1);
        if (file.lines[lineCount] == NULL) {
            printf("Memory allocation failed\n");
            break;
        }
        strcpy(file.lines[lineCount], file.buffer);
        lineCount++;
    }
    file.lineAmount = lineCount;

    if(print){
        printFile(file); //Printing our file for debug purposes
    }

    //close our file (tbh idk why this is neccesary, since we dont write to the file, maybe for memory management)
    fclose(file.filePtr);
    return file;
}

int main() {
    readFile("example.dub",true);
}