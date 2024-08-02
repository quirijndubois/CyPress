# Compilation bash script for CyPDF

source="CyPDF/src/*.c"
include="CyPDF/include"
gccFlags="-fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter"

gcc -I$include $gccFlags $source -o cypdf.out
./cypdf.out
rm ./cypdf.out
