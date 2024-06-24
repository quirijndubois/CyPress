# Simple compilation bash script (no windows)
# Made for rapid compiling and testing

source="*.c"
gccFlags="-fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter"

echo
gcc $source $gccFlags
./a.out
rm ./a.out
