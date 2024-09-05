cmake_minimum_required(VERSION 3.10)

project(CyPress)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_C_STANDARD 11)

add_executable(CyPress src/compile.c src/parser/parser.c src/parser/tokenizer.c src/parser/tree_generator.c src/parser/utils.c)
file(COPY logo.txt DESTINATION ${CMAKE_BINARY_DIR})
