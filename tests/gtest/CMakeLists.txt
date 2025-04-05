find_package(GTest REQUIRED)

add_executable(testex unit_test.cpp)
target_compile_options(testex PUBLIC -Wall -Wextra -Wpedantic)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/include/path_getter.h
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/path_getter/path_getter.rb
            ${CMAKE_CURRENT_SOURCE_DIR}/path_getter/path_getter.h.erb
            ${CMAKE_BINARY_DIR}/include/path_getter.h
            "${CMAKE_CURRENT_SOURCE_DIR}/../test_files/"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/path_getter/path_getter.h.erb)

add_custom_target(path_getter
    DEPENDS ${CMAKE_BINARY_DIR}/include/path_getter.h)
add_dependencies(testex path_getter)

target_include_directories(testex PRIVATE ${GTEST_INCLUDE_DIRS} 
                                          ${CMAKE_CURRENT_SOURCE_DIR}/../../matrix/ 
                                          ${CMAKE_BINARY_DIR}/include)
target_link_libraries(testex GTest::GTest GTest::Main)

add_test(NAME gtest_test COMMAND testex)