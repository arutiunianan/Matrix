cmake_minimum_required(VERSION 3.10)

project(matrixlib)

add_library(matrixlib STATIC matrix.cpp)
target_include_directories(matrixlib PUBLIC {CMAKE_CURRENT_SOURCE_DIR})
