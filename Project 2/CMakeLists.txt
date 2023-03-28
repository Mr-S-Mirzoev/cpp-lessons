cmake_minimum_required(VERSION 3.8)

project(
    long_number
    VERSION 0.0.1
    LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED long_number.cpp long_number.h)

set(TEST_NAME ln_test)

add_executable(${TEST_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_ROOT_DIR})
target_link_libraries(${TEST_NAME} ${PROJECT_NAME})

add_test(NAME ${TEST_NAME}
         COMMAND $<TARGET_FILE:${TEST_NAME}>)