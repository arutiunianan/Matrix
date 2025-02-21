#ifndef CONSTRUCTORS_H_
#define CONSTRUCTORS_H_

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "path_getter.h"
#include "matrix.h"

template <typename T>
void runCopyConstructor(size_t file_num) {
    std::string file_path = testPathGet(file_num);
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    Matrix_t<T> new_matrix = matrix;

    test_file.seekg(0);

    size_t ans_N;
    test_file >> ans_N;
    Matrix_t<T> ans_matrix(ans_N);
    test_file >> ans_matrix;

    test_file.close();

    ASSERT_TRUE(new_matrix == ans_matrix);
}

TEST(CopyConstructor, Subtestv_1) {
    runCopyConstructor<double>(1);
}

TEST(CopyConstructor, Subtestv_2) {
    runCopyConstructor<double>(2);
}

TEST(CopyConstructor, Subtestv_3) {
    runCopyConstructor<double>(3);
}

TEST(CopyConstructor, Subtestv_4) {
    runCopyConstructor<double>(4);
}

TEST(CopyConstructor, Subtestv_5) {
    runCopyConstructor<double>(5);
}

TEST(CopyConstructor, Subtestv_6) {
    runCopyConstructor<double>(6);
}

TEST(CopyConstructor, Subtestv_7) {
    runCopyConstructor<double>(7);
}

TEST(CopyConstructor, Subtestv_8) {
    runCopyConstructor<double>(8);
}

TEST(CopyConstructor, Subtestv_9) {
    runCopyConstructor<double>(9);
}

TEST(CopyConstructor, Subtestv_10) {
    runCopyConstructor<double>(10);
}

TEST(CopyConstructor, Subtestv_11) {
    runCopyConstructor<double>(11);
}

TEST(CopyConstructor, Subtestv_12) {
    runCopyConstructor<double>(12);
}

TEST(CopyConstructor, Subtestv_13) {
    runCopyConstructor<double>(13);
}

TEST(CopyConstructor, Subtestv_14) {
    runCopyConstructor<double>(14);
}

TEST(CopyConstructor, Subtestv_15) {
    runCopyConstructor<double>(15);
}

// ----------------------------------------------------------------------------------------

template <typename T>
void runCopyAssignment(size_t file_num) {
    std::string file_path = testPathGet(file_num);
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    Matrix_t<T> new_matrix(N);
    new_matrix = matrix;

    test_file.seekg(0);

    size_t ans_N;
    test_file >> ans_N;
    Matrix_t<T> ans_matrix(ans_N);
    test_file >> ans_matrix;

    test_file.close();

    ASSERT_TRUE(new_matrix == ans_matrix);
}

TEST(CopyAssignment, Subtestv_1) {
    runCopyAssignment<double>(1);
}

TEST(CopyAssignment, Subtestv_2) {
    runCopyAssignment<double>(2);
}

TEST(CopyAssignment, Subtestv_3) {
    runCopyAssignment<double>(3);
}

TEST(CopyAssignment, Subtestv_4) {
    runCopyAssignment<double>(4);
}

TEST(CopyAssignment, Subtestv_5) {
    runCopyAssignment<double>(5);
}

TEST(CopyAssignment, Subtestv_6) {
    runCopyAssignment<double>(6);
}

TEST(CopyAssignment, Subtestv_7) {
    runCopyAssignment<double>(7);
}

TEST(CopyAssignment, Subtestv_8) {
    runCopyAssignment<double>(8);
}

TEST(CopyAssignment, Subtestv_9) {
    runCopyAssignment<double>(9);
}

TEST(CopyAssignment, Subtestv_10) {
    runCopyAssignment<double>(10);
}

TEST(CopyAssignment, Subtestv_11) {
    runCopyAssignment<double>(11);
}

TEST(CopyAssignment, Subtestv_12) {
    runCopyAssignment<double>(12);
}

TEST(CopyAssignment, Subtestv_13) {
    runCopyAssignment<double>(13);
}

TEST(CopyAssignment, Subtestv_14) {
    runCopyAssignment<double>(14);
}

TEST(CopyAssignment, Subtestv_15) {
    runCopyAssignment<double>(15);
}

// ----------------------------------------------------------------------------------------

template <typename T>
void runMoveConstructor(size_t file_num) {
    std::string file_path = testPathGet(file_num);
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    Matrix_t<T> new_matrix(N);
    new_matrix = std::move(matrix);

    test_file.seekg(0);

    size_t ans_N;
    test_file >> ans_N;
    Matrix_t<T> ans_matrix(ans_N);
    test_file >> ans_matrix;

    test_file.close();

    ASSERT_TRUE(new_matrix == ans_matrix);
}

TEST(MoveConstructor, Subtestv_1) {
    runMoveConstructor<double>(1);
}

TEST(MoveConstructor, Subtestv_2) {
    runMoveConstructor<double>(2);
}

TEST(MoveConstructor, Subtestv_3) {
    runMoveConstructor<double>(3);
}

TEST(MoveConstructor, Subtestv_4) {
    runMoveConstructor<double>(4);
}

TEST(MoveConstructor, Subtestv_5) {
    runMoveConstructor<double>(5);
}

TEST(MoveConstructor, Subtestv_6) {
    runMoveConstructor<double>(6);
}

TEST(MoveConstructor, Subtestv_7) {
    runMoveConstructor<double>(7);
}

TEST(MoveConstructor, Subtestv_8) {
    runMoveConstructor<double>(8);
}

TEST(MoveConstructor, Subtestv_9) {
    runMoveConstructor<double>(9);
}

TEST(MoveConstructor, Subtestv_10) {
    runMoveConstructor<double>(10);
}

TEST(MoveConstructor, Subtestv_11) {
    runMoveConstructor<double>(11);
}

TEST(MoveConstructor, Subtestv_12) {
    runMoveConstructor<double>(12);
}

TEST(MoveConstructor, Subtestv_13) {
    runMoveConstructor<double>(13);
}

TEST(MoveConstructor, Subtestv_14) {
    runMoveConstructor<double>(14);
}

TEST(MoveConstructor, Subtestv_15) {
    runMoveConstructor<double>(15);
}

// ----------------------------------------------------------------------------------------

template <typename T>
void runMoveAssignment(size_t file_num) {
    std::string file_path = testPathGet(file_num);
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    Matrix_t<T> new_matrix(N);
    new_matrix = matrix;

    test_file.seekg(0);

    size_t ans_N;
    test_file >> ans_N;
    Matrix_t<T> ans_matrix(ans_N);
    test_file >> ans_matrix;

    test_file.close();

    ASSERT_TRUE(new_matrix == ans_matrix);
}

TEST(MoveAssignment, Subtestv_1) {
    runMoveAssignment<double>(1);
}

TEST(MoveAssignment, Subtestv_2) {
    runMoveAssignment<double>(2);
}

TEST(MoveAssignment, Subtestv_3) {
    runMoveAssignment<double>(3);
}

TEST(MoveAssignment, Subtestv_4) {
    runMoveAssignment<double>(4);
}

TEST(MoveAssignment, Subtestv_5) {
    runMoveAssignment<double>(5);
}

TEST(MoveAssignment, Subtestv_6) {
    runMoveAssignment<double>(6);
}

TEST(MoveAssignment, Subtestv_7) {
    runMoveAssignment<double>(7);
}

TEST(MoveAssignment, Subtestv_8) {
    runMoveAssignment<double>(8);
}

TEST(MoveAssignment, Subtestv_9) {
    runMoveAssignment<double>(9);
}

TEST(MoveAssignment, Subtestv_10) {
    runMoveAssignment<double>(10);
}

TEST(MoveAssignment, Subtestv_11) {
    runMoveAssignment<double>(11);
}

TEST(MoveAssignment, Subtestv_12) {
    runMoveAssignment<double>(12);
}

TEST(MoveAssignment, Subtestv_13) {
    runMoveAssignment<double>(13);
}

TEST(MoveAssignment, Subtestv_14) {
    runMoveAssignment<double>(14);
}

TEST(MoveAssignment, Subtestv_15) {
    runMoveAssignment<double>(15);
}

#endif  // CONSTRUCTORS_H_