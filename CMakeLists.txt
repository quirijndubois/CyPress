set(CMAKE_MINIMUM_REQUIRED_VERSION 3.10)

project(CyPress)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_C_STANDARD 11)

add_executable(CyPress compile.c parser/parser.c parser/tokenizer.c parser/tree_generator.c parser/utils.c)
