cmake_minimum_required(VERSION 3.8)

project(
    geometry
    VERSION 0.0.1
    LANGUAGES CXX)

add_executable(geometry
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/shape.cpp ${PROJECT_SOURCE_DIR}/shape.h
    ${PROJECT_SOURCE_DIR}/rectangle.cpp ${PROJECT_SOURCE_DIR}/rectangle.h
    ${PROJECT_SOURCE_DIR}/triangle.cpp ${PROJECT_SOURCE_DIR}/triangle.h)
