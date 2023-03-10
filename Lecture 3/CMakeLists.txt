cmake_minimum_required(VERSION 3.8)

project(
    l3
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(loops ${PROJECT_SOURCE_DIR}/loops.cpp)
add_executable(structs ${PROJECT_SOURCE_DIR}/structs.cpp)

add_subdirectory(linked_list)