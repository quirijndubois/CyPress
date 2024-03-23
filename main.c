#include <stdio.h>

#define DEBUG

int main(int argc, char* argv[argc + 1]) {
#ifdef DEBUG
    puts("Hello, World!");
#endif

    return 0;
}
