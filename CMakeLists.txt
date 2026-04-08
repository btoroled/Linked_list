cmake_minimum_required(VERSION 4.2)
project(Linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Linked_list
        linkedlist.cpp
        linkedlist.h)
