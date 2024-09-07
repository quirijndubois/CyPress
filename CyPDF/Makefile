# Define the compiler and the flags
CFLAGS = -fdiagnostics-color=always -Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter
SRC_DIR = CyPDF/src
INCLUDE_DIR = CyPDF/include
OUTPUT = cypdf.out

SOURCES = $(wildcard $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

compile: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	gcc -I$(INCLUDE_DIR) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

run: compile
	./$(OUTPUT)
	rm -f $(OUTPUT)

clean:
	rm -f $(OUTPUT)

.PHONY: compile run clean
