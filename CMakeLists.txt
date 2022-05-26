cmake_minimum_required(VERSION 3.22)
project(asserts C)
set(CMAKE_C_STANDARD 11)
add_definitions(-DDEBUG)

add_executable(asserts main.c my_assert.h test/main.h test/main.c my_assert.c)
