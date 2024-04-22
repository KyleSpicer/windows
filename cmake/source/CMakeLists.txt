cmake_minimum_required(VERSION 3.2)

project(MyProgram C)

add_library(Helpers 
    src/helpers.c
)

add_executable(MyProgram 
    src/main.c
)

target_link_libraries(MyProgram PRIVATE Helpers)


