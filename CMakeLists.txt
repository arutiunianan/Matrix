cmake_minimum_required(VERSION 3.10)

project(matrix)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(matrix main.cpp)

find_package(GTest REQUIRED)

enable_testing()
add_definitions(-DCMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(testex tests/unit_test.cpp)
target_include_directories(testex PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(testex GTest::GTest GTest::Main)

add_test(NAME mytest COMMAND testex)