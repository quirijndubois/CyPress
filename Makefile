source := main.c
exeName := rooster
gccFlags := -fdiagnostics-color=always -Wall

run: ${exeName}.exe
	.\${exeName}.exe

compile: ${exeName}.exe

rooster.exe: ${source}
	gcc ${gccFlags} ${source} -o ${exeName}