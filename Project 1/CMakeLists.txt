cmake_minimum_required(VERSION 3.8)

project(
    linked_list_basic
    VERSION 0.0.1
    LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED linked_list.cpp linked_list.h)

add_executable(test ${PROJECT_SOURCE_DIR}/test.cpp)
target_include_directories(test PRIVATE ${PROJECT_ROOT_DIR})
target_link_libraries(test ${PROJECT_NAME})