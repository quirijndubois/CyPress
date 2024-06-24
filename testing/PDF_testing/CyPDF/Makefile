source := $(wildcard *.c)
exeName := rooster
gccFlags := -fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter

run: ${exeName}.exe
	.\${exeName}.exe

compile: ${exeName}.exe

rooster.exe: ${source}
	gcc ${gccFlags} ${source} -o ${exeName}