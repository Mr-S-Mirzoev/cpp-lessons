cmake_minimum_required(VERSION 3.1)

project(
    CppCourses
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/bin)
add_subdirectory("Lecture 1")
add_subdirectory("Lecture 2")
add_subdirectory("Lecture 3")
add_subdirectory("Project 1")
