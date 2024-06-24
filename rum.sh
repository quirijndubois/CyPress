# Simple compilation bash script (no windows)
# Made for rapid compiling and testing

source="CyPDF/src/*.c"
gccFlags="-fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter"

echo
gcc -ICyPDF/include $gccFlags $source
./a.out
rm ./a.out
