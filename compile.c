// This file as meant as full stack compiler (main file), please dont put any main functions in any other .c files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser/parser.h"
#include "utils.h"

int main(){
    print_logo();
    parse("example.cyp");
}