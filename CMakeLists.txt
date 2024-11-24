cmake_minimum_required(VERSION 3.10)

project(matrix)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_subdirectory(matrix)

if(TEST)
    add_executable(test test/unit_test.cpp)
    target_link_libraries(test PRIVATE matrixlib)

    target_include_directories(test PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(test GTest::GTest GTest::Main)
else()
    add_executable(matrix_ main.cpp)
    target_link_libraries(matrix_ PRIVATE matrixlib)
endif()