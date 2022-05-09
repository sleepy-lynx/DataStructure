cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(KernelLinkedList)

add_executable(DataStructure
        KernelLinkedList/main.c)
