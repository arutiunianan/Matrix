#ifndef DETERMINANT_H_
#define DETERMINANT_H_

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "path_getter.h"
#include "matrix.h"

template <typename T>
void runTestFromFile(size_t file_num) {
    std::string file_path = testPathGet(file_num);
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    std::string ans_file_path = testAnsPathGet(file_num);
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
    std::istringstream input("4 2 3 4 5 6 7 8 9\n");
    input >> matrix;
    
    double answer = -9;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_2) {
    Matrix_t<double> matrix(3);
    std::istringstream input("4 2 3 4 5 6 7 8 9\n");
    input >> matrix;
    
    double answer = -9;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_3) {
    Matrix_t<double> matrix(4);
    std::istringstream input("2 4 -1 1 -1 2 1 -1 1 -6 3 -1 2 0 3 -1\n");
    input >> matrix;
    
    double answer = 0;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_4) {
    Matrix_t<double> matrix(3);
    std::istringstream input("1 5 3 2 4 7 4 6 2\n");
    input >> matrix;
    
    double answer = 74;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_5) {
    runTestFromFile<double>(1);
}

TEST(Determinant, Subtestv_6) {
    runTestFromFile<double>(2);
}

TEST(Determinant, Subtestv_7) {
    runTestFromFile<double>(3);
}

TEST(Determinant, Subtestv_8) {
    runTestFromFile<double>(4);
}

TEST(Determinant, Subtestv_9) {
    runTestFromFile<double>(5);
}

TEST(Determinant, Subtestv_10) {
    runTestFromFile<double>(6);
}

TEST(Determinant, Subtestv_11) {
    runTestFromFile<double>(7);
}

TEST(Determinant, Subtestv_12) {
    runTestFromFile<double>(8);
}

TEST(Determinant, Subtestv_13) {
    runTestFromFile<double>(9);
}

TEST(Determinant, Subtestv_14) {
    runTestFromFile<double>(10);
}

TEST(Determinant, Subtestv_15) {
    runTestFromFile<double>(11);
}

TEST(Determinant, Subtestv_16) {
    runTestFromFile<double>(12);
}

TEST(Determinant, Subtestv_17) {
    runTestFromFile<double>(13);
}

TEST(Determinant, Subtestv_18) {
    runTestFromFile<double>(14);
}

TEST(Determinant, Subtestv_19) {
    runTestFromFile<double>(15);
}

TEST(Determinant, Subtestv_20) {
    runTestFromFile<double>(16);
}

TEST(Determinant, Subtestv_21) {
    runTestFromFile<double>(17);
}

TEST(Determinant, Subtestv_22) {
    runTestFromFile<double>(18);
}

TEST(Determinant, Subtestv_23) {
    runTestFromFile<double>(19);
}

TEST(Determinant, Subtestv_24) {
    runTestFromFile<double>(20);
}

TEST(Determinant, Subtestv_25) {
    runTestFromFile<double>(21);
}

TEST(Determinant, Subtestv_26) {
    runTestFromFile<double>(22);
}

TEST(Determinant, Subtestv_27) {
    runTestFromFile<double>(23);
}

TEST(Determinant, Subtestv_28) {
    runTestFromFile<double>(24);
}

TEST(Determinant, Subtestv_29) {
    runTestFromFile<double>(25);
}

TEST(Determinant, Subtestv_30) {
    runTestFromFile<double>(26);
}

TEST(Determinant, Subtestv_31) {
    runTestFromFile<double>(27);
}

TEST(Determinant, Subtestv_32) {
    runTestFromFile<double>(28);
}

TEST(Determinant, Subtestv_33) {
    runTestFromFile<double>(29);
}

TEST(Determinant, Subtestv_34) {
    runTestFromFile<double>(30);
}

#endif // DETERMINANT_H_