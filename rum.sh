# Compilation bash script for CyPDF

source="CyPDF/src/*.c"
gccFlags="-fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter"

gcc -ICyPDF/include $gccFlags $source
./a.out
rm ./a.out
