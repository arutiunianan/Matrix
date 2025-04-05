cmake_minimum_required(VERSION 3.10)

project(matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(matrix main.cpp)
target_compile_options(matrix PUBLIC -Wall -Wextra -Wpedantic)
target_include_directories(matrix PRIVATE matrix/)

find_package(GTest REQUIRED)

enable_testing()

add_executable(testex tests/unit_test.cpp)
target_compile_options(testex PUBLIC -Wall -Wextra -Wpedantic)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/include/path_getter.h
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/path_getter/path_getter.rb
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/path_getter/path_getter.h.erb
            ${CMAKE_BINARY_DIR}/include/path_getter.h
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_files/"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/path_getter/path_getter.h.erb)

add_custom_target(path_getter
    DEPENDS ${CMAKE_BINARY_DIR}/include/path_getter.h)
add_dependencies(testex path_getter)

target_include_directories(testex PRIVATE ${GTEST_INCLUDE_DIRS} 
                                          matrix/ 
                                          ${CMAKE_BINARY_DIR}/include)
target_link_libraries(testex GTest::GTest GTest::Main)

add_test(NAME gtest_test COMMAND testex)

add_test(NAME end2end_test
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.sh
            ${CMAKE_CURRENT_SOURCE_DIR}
            $<TARGET_FILE:matrix> 30
)