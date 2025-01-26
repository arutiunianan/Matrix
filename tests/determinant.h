#ifndef DETERMINANT_H_
#define DETERMINANT_H_

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "../matrix/matrix.h"

template <typename T>
void run_test_from_file(size_t file_num) {
    std::string file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) 
                          + "/tests/test_files/file" 
                          + std::to_string(file_num) 
                          + ".txt";
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    std::string ans_file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) 
                              + "/tests/test_files/file" 
                              + std::to_string(file_num) 
                              + "ans.txt";
    std::ifstream test_ans_file;
    test_ans_file.open(ans_file_path);

    T answer;
    test_ans_file >> answer;


    test_file.close();
    test_ans_file.close();

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}


TEST(Determinant, Subtestv_1) {
    Matrix_t<double> matrix(3);
    std::istringstream input("4 2 3 4 5 6 7 8 9");
    input >> matrix;
    
    double answer = -9;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_2) {
    Matrix_t<double> matrix(3);
    std::istringstream input("4 2 3 4 5 6 7 8 9");
    input >> matrix;
    
    double answer = -9;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_3) {
    Matrix_t<double> matrix(4);
    std::istringstream input("2 4 -1 1 -1 2 1 -1 1 -6 3 -1 2 0 3 -1");
    input >> matrix;
    
    double answer = 0;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_4) {
    Matrix_t<double> matrix(3);
    std::istringstream input("1 5 3 2 4 7 4 6 2");
    input >> matrix;
    
    double answer = 74;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_5) {
    run_test_from_file<double>(1);
}

TEST(Determinant, Subtestv_6) {
    run_test_from_file<double>(2);
}

TEST(Determinant, Subtestv_7) {
    run_test_from_file<double>(3);
}

TEST(Determinant, Subtestv_8) {
    run_test_from_file<double>(4);
}

TEST(Determinant, Subtestv_9) {
    run_test_from_file<double>(5);
}

TEST(Determinant, Subtestv_10) {
    run_test_from_file<double>(6);
}

TEST(Determinant, Subtestv_11) {
    run_test_from_file<double>(7);
}

TEST(Determinant, Subtestv_12) {
    run_test_from_file<double>(8);
}

TEST(Determinant, Subtestv_13) {
    run_test_from_file<double>(9);
}

TEST(Determinant, Subtestv_14) {
    run_test_from_file<double>(10);
}

TEST(Determinant, Subtestv_15) {
    run_test_from_file<double>(11);
}

TEST(Determinant, Subtestv_16) {
    run_test_from_file<double>(12);
}

TEST(Determinant, Subtestv_17) {
    run_test_from_file<double>(13);
}

TEST(Determinant, Subtestv_18) {
    run_test_from_file<double>(14);
}

TEST(Determinant, Subtestv_19) {
    run_test_from_file<double>(15);
}

TEST(Determinant, Subtestv_20) {
    run_test_from_file<double>(16);
}

TEST(Determinant, Subtestv_21) {
    run_test_from_file<double>(17);
}

TEST(Determinant, Subtestv_22) {
    run_test_from_file<double>(18);
}

TEST(Determinant, Subtestv_23) {
    run_test_from_file<double>(19);
}

TEST(Determinant, Subtestv_24) {
    run_test_from_file<double>(20);
}

TEST(Determinant, Subtestv_25) {
    run_test_from_file<double>(21);
}

TEST(Determinant, Subtestv_26) {
    run_test_from_file<double>(22);
}

TEST(Determinant, Subtestv_27) {
    run_test_from_file<double>(23);
}

TEST(Determinant, Subtestv_28) {
    run_test_from_file<double>(24);
}

TEST(Determinant, Subtestv_29) {
    run_test_from_file<double>(25);
}

TEST(Determinant, Subtestv_30) {
    run_test_from_file<double>(26);
}

TEST(Determinant, Subtestv_31) {
    run_test_from_file<double>(27);
}

TEST(Determinant, Subtestv_32) {
    run_test_from_file<double>(28);
}

TEST(Determinant, Subtestv_33) {
    run_test_from_file<double>(29);
}

TEST(Determinant, Subtestv_34) {
    run_test_from_file<double>(30);
}

#endif // DETERMINANT_H_