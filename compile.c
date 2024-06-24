// This file as meant as full stack compiler (main file)
// Please dont put any main functions in any other files that are included in pipeline

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser/parser.h"
#include "utils.h"

int main(int argc, char* argv[]){
    print_logo();

    char* path = argv[1];
    parse(path);
}
