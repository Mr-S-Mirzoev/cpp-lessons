cmake_minimum_required(VERSION 3.8)

project(
    l5
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(encapsulation ${PROJECT_SOURCE_DIR}/encapsulation.cpp)
add_executable(inheritance ${PROJECT_SOURCE_DIR}/inheritance.cpp)
add_executable(polymorphism ${PROJECT_SOURCE_DIR}/polymorphism.cpp)
add_subdirectory("geometry")
