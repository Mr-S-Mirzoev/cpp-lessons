cmake_minimum_required(VERSION 3.8)

project(
    linked_list_basic
    VERSION 0.0.1
    LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED linked_list.cpp linked_list.h)

set(TEST_NAME ll_test)

add_executable(${TEST_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_ROOT_DIR})
target_link_libraries(${TEST_NAME} ${PROJECT_NAME})

add_test(NAME linked_list_test
         COMMAND $<TARGET_FILE:ll_test>)