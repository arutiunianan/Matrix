#ifndef DETERMINANT_H_
#define DETERMINANT_H_

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "../matrix/matrix.h"

template <typename T>
void run_test_from_file(size_t file_num) {
    std::string file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/tests/test_files/file" + 
                            std::to_string(file_num) + ".txt";
    std::ifstream test_file;
    test_file.open(file_path);

    size_t N;
    test_file >> N;
    Matrix_t<T> matrix(N);
    test_file >> matrix;

    std::string ans_file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/tests/test_files/file" + 
                                std::to_string(file_num) + "ans.txt";
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
    Matrix_t<double> matrix(10);
    std::istringstream input("0.6478 0.6674 1.8214 0.5554 1.849 1.6148 1.3542 1.3444 1.0762 1.2262 1.8348 1.0534 0.5918 0.8024 0.4836 0.756 1.4224 1.6552 1.2264 0.0524 1.59 1.276 0.9918 1.2604 0.1724 0.4392 1.7048 1.6136 1.9234 0.7598 0.069 0.5712 0.6976 1.8904 1.1268 1.817 0.7756 1.7514 0.4318 1.1222 0.9778 0.2666 0.1756 1.5696 0.3394 0.6594 1.596 1.0322 0.3146 0.8224 1.0848 1.1752 0.0986 1.347 0.4356 1.5414 1.7862 0.1404 0.4256 0.98 0.1706 0.4946 0.8216 0.1386 1.6554 1.9484 1.9556 1.7016 1.7 0.3874 0.8238 1.9482 1.9246 0.27 0.7882 1.5344 0.1998 0.3842 0.5668 1.7848 0.477 0.922 0.96 0.5756 0.269 1.3956 1.3876 1.3256 0.8064 1.0836 1.576 0.977 0.8486 0.3976 1.1156 0.504 1.6166 1.0712 1.476 0.587");
    input >> matrix;
    
    double answer = 0.761572;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.000001f);
}

TEST(Determinant, Subtestv_6) {
    Matrix_t<double> matrix(10);
    std::istringstream input("0.6478 0.6674 1.8214 0.5554 1.849 1.6148 1.3542 1.3444 1.0762 1.2262  1.8348 1.0534 0.5918 0.8024 0.4836 0.756 1.4224 1.6552 1.2264 0.0524   1.59 1.276 0.9918 1.2604 0.1724 0.4392 1.7048 1.6136 1.9234 0.7598  0.069 0.5712 0.6976 1.8904 1.1268 1.817 0.7756 1.7514 0.4318 1.1222  0.9778 0.2666 0.1756 1.5696 0.3394 0.6594 1.596 1.0322 0.3146 0.8224  1.0848 1.1752 0.0986 1.347 0.4356 1.5414 1.7862 0.1404 0.4256  0.98  0.1706 0.4946 0.8216 0.1386 1.6554 1.9484 1.9556 1.7016   1.7 0.3874  0.8238 1.9482 1.9246  0.27 0.7882 1.5344 0.1998 0.3842 0.5668 1.7848  0.477 0.922  0.96 0.5756 0.269 1.3956 1.3876 1.3256 0.8064 1.0836  0 0 0 0 0 0 0 0 0 0");
    input >> matrix;
    
    double answer = 0;

    ASSERT_NEAR(matrix.BareissAlgorithm(), answer, 0.0001f);
}

TEST(Determinant, Subtestv_7) {
    run_test_from_file<double>(1);
}

TEST(Determinant, Subtestv_8) {
    run_test_from_file<double>(2);
}

TEST(Determinant, Subtestv_9) {
    run_test_from_file<double>(3);
}

TEST(Determinant, Subtestv_10) {
    run_test_from_file<double>(4);
}

TEST(Determinant, Subtestv_11) {
    run_test_from_file<double>(5);
}

TEST(Determinant, Subtestv_12) {
    run_test_from_file<double>(6);
}

TEST(Determinant, Subtestv_13) {
    run_test_from_file<double>(7);
}

TEST(Determinant, Subtestv_14) {
    run_test_from_file<double>(8);
}

TEST(Determinant, Subtestv_15) {
    run_test_from_file<double>(9);
}

TEST(Determinant, Subtestv_16) {
    run_test_from_file<double>(10);
}

TEST(Determinant, Subtestv_17) {
    run_test_from_file<double>(11);
}

TEST(Determinant, Subtestv_18) {
    run_test_from_file<double>(12);
}

TEST(Determinant, Subtestv_19) {
    run_test_from_file<double>(13);
}

TEST(Determinant, Subtestv_20) {
    run_test_from_file<double>(14);
}

TEST(Determinant, Subtestv_21) {
    run_test_from_file<double>(15);
}

TEST(Determinant, Subtestv_22) {
    run_test_from_file<double>(16);
}

TEST(Determinant, Subtestv_23) {
    run_test_from_file<double>(17);
}

TEST(Determinant, Subtestv_24) {
    run_test_from_file<double>(18);
}

TEST(Determinant, Subtestv_25) {
    run_test_from_file<double>(19);
}

TEST(Determinant, Subtestv_26) {
    run_test_from_file<double>(20);
}

TEST(Determinant, Subtestv_27) {
    run_test_from_file<double>(21);
}

TEST(Determinant, Subtestv_28) {
    run_test_from_file<double>(22);
}

TEST(Determinant, Subtestv_29) {
    run_test_from_file<double>(23);
}

TEST(Determinant, Subtestv_30) {
    run_test_from_file<double>(24);
}

TEST(Determinant, Subtestv_31) {
    run_test_from_file<double>(25);
}

TEST(Determinant, Subtestv_32) {
    run_test_from_file<double>(26);
}

TEST(Determinant, Subtestv_33) {
    run_test_from_file<double>(27);
}

TEST(Determinant, Subtestv_34) {
    run_test_from_file<double>(28);
}

#endif // DETERMINANT_H_