cmake_minimum_required(VERSION 3.10)

project(matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(matrix main.cpp)
target_compile_options(matrix PUBLIC -Wall -Wextra -Wpedantic)
target_include_directories(matrix PRIVATE matrix/)

enable_testing()
add_subdirectory(tests)