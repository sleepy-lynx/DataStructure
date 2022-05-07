cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(dynamicArray)

add_executable(DataStructure
        Inheritance/main.c
        Inheritance/Object.c Inheritance/Object.h)
