cmake_minimum_required(VERSION 3.8)

project(
    l2
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(mem ${PROJECT_SOURCE_DIR}/mem_alloc.cpp)
add_executable(pointers ${PROJECT_SOURCE_DIR}/pointers.cpp)