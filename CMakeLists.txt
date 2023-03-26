cmake_minimum_required(VERSION 3.1)

project(
    CppCourses
    VERSION 1.0
    LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/bin)

# enable testing functionality
enable_testing()

add_subdirectory("Lecture 1")
add_subdirectory("Lecture 2")
add_subdirectory("Lecture 3")
add_subdirectory("Lecture 4")
add_subdirectory("Project 1")
