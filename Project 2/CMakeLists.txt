cmake_minimum_required(VERSION 3.8)

project(
    hash_table
    VERSION 0.0.1
    LANGUAGES CXX)

set(TEST_NAME hash_table_test)

add_executable(${TEST_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_ROOT_DIR})
target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_SOURCE_DIR})

add_test(NAME ${TEST_NAME}
         COMMAND $<TARGET_FILE:${TEST_NAME}>)