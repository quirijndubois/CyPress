exeName := rooster
gccFlags := -fdiagnostics-color=always -Wall

run: ${exeName}.exe
	.\${exeName}.exe

comp: ${exeName}.exe

rooster.exe: main.c
	gcc ${gccFlags} main.c -o ${exeName}