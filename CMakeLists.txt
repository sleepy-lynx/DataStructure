cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(dynamicArray)

add_executable(DataStructure
        dynamicArray/dynamicArray.c
        dynamicArray/dynamicArray.h
        dynamicArray/main.c
        dynamicArray/object.c
        dynamicArray/object.h)
