cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(KernelLinkedList)

add_executable(DataStructure
        DynamicArray/object.h
        DynamicArray/object.c
        DynamicArray/dynamicArray.h
        DynamicArray/dynamicArray.c
        DynamicArray/myString.h
        DynamicArray/myString.c
        DynamicArray/main.c)
