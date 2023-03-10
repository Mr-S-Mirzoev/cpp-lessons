cmake_minimum_required(VERSION 3.8)

project(
    l1
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(basics ${PROJECT_SOURCE_DIR}/basics.cpp)
add_executable(functions ${PROJECT_SOURCE_DIR}/functions.cpp)
