cmake_minimum_required(VERSION 3.26)
project(task12-1 C)

set(CMAKE_C_STANDARD 23)

add_executable(task12-1 main.c lexerTest.c lexerTest.h realNumberLexer.c realNumberLexer.h)