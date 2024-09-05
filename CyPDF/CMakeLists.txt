cmake_minimum_required(VERSION 3.10)

project(CyPDF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(include)

add_executable(CyPDF src/main.c src/cypdf_array.c src/cypdf_bool.c src/cypdf_catalog.c src/cypdf_dict.c src/cypdf_doc.c src/cypdf_header.c src/cypdf_info.c src/cypdf_list.c src/cypdf_name.c src/cypdf_null.c src/cypdf_number.c src/cypdf_object.c src/cypdf_pages.c src/cypdf_print.c src/cypdf_real.c src/cypdf_string.c src/cypdf_trailer.c src/cypdf_utils.c src/cypdf_xref.c src/main.c src/md5.c)
