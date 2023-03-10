cmake_minimum_required(VERSION 3.8)

project(
    l1
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(structs ${PROJECT_SOURCE_DIR}/structs.cpp)
add_executable(loops ${PROJECT_SOURCE_DIR}/loops.cpp)
add_executable(pointers ${PROJECT_SOURCE_DIR}/pointers.cpp)
add_executable(mem ${PROJECT_SOURCE_DIR}/mem_alloc.cpp)