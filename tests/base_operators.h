#ifndef BASE_OPERATORS_H_
#define BASE_OPERATORS_H_

#include <gtest/gtest.h>
#include "../matrix/matrix.h"

TEST(Transpose, Subtestv_1) {
    Matrix_t<int> matrix(3);
    std::istringstream input("1 2 3 4 5 6 7 8 9");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("1 4 7 2 5 8 3 6 9");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_2) {
    Matrix_t<int> matrix(3);
    std::istringstream input("0 0 0 0 0 0 0 0 0");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("0 0 0 0 0 0 0 0 0");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_3) {
    Matrix_t<int> matrix(1);
    std::istringstream input("-2");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(1);
    std::istringstream ans_input("-2");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_4) {
    Matrix_t<int> matrix(2, 3);
    std::istringstream input("2 1 -3 0 4 -1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3, 2);
    std::istringstream ans_input("2 0 1 4 -3 -1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_5) {
    Matrix_t<int> matrix(3, 2);
    std::istringstream input("2 1 -3 0 4 -1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(2, 3);
    std::istringstream ans_input("2 -3 4 1 0 -1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_6) {
    Matrix_t<int> matrix(4);
    std::istringstream input("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(4);
    std::istringstream ans_input("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

TEST(Transpose, Subtestv_7) {
    Matrix_t<int> matrix(3);
    matrix.getIdentityMatrix();
    
    Matrix_t<int> ans_matrix(3);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix.transpose() == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Multiplication, Subtestv_1) {
    Matrix_t<int> matrix1(2);
    std::istringstream input1("4 2 9 0");
    input1 >> matrix1;

    Matrix_t<int> matrix2(2);
    std::istringstream input2("3 1 -3 4");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(2);
    std::istringstream ans_input("6 12 27 9");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_2) {
    Matrix_t<int> matrix1(3, 2);
    std::istringstream input1("2 1 -3 0 4 -1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(2, 3);
    std::istringstream input2("5 -1 6 -3 0 7");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(3, 3);
    std::istringstream ans_input("7 -2 19 -15 3 -18 23 -4 17");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_3) {
    Matrix_t<int> matrix1(3);
    std::istringstream input1("2 -1 3 4 2 0 -1 1 1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(3, 1);
    std::istringstream input2("1 2 -1");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(3, 1);
    std::istringstream ans_input("-3 8 0");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_4) {
    Matrix_t<int> matrix1(3, 1);
    std::istringstream input1("1 2 3");
    input1 >> matrix1;

    Matrix_t<int> matrix2(1, 3);
    std::istringstream input2("-2 -3 4");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("-2 -3 4 -4 -6 8 -6 -9 12");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_5) {
    Matrix_t<int> matrix1(1, 3);
    std::istringstream input1("-2 -3 4");
    input1 >> matrix1;

    Matrix_t<int> matrix2(3, 1);
    std::istringstream input2("1 2 3");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(1);
    std::istringstream ans_input("4");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_6) {
    Matrix_t<int> matrix1(2);
    std::istringstream input1("3 5 2 1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(2, 3);
    std::istringstream input2("8 2 3 1 7 2");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(2, 3);
    std::istringstream ans_input("29 41 19 17 11 8");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_7) {
    Matrix_t<int> matrix1(3);
    std::istringstream input1("1 4 3 2 1 5 3 2 1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(3);
    matrix2.getIdentityMatrix();
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("1 4 3 2 1 5 3 2 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_8) {
    Matrix_t<int> matrix1(3);
    matrix1.getIdentityMatrix();

    Matrix_t<int> matrix2(3);
    std::istringstream input2("1 4 3 2 1 5 3 2 1");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("1 4 3 2 1 5 3 2 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_9) {
    Matrix_t<int> matrix1(4);
    std::istringstream input1("1 0 2 -1 -2 0 -4 2 1 0 2 -1 3 0 6 -3");
    input1 >> matrix1;

    Matrix_t<int> matrix2(4);
    std::istringstream input2("2 1 3 -1 -4 -2 -6 2 2 1 3 -1 6 3 9 -3");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(4);

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

TEST(Multiplication, Subtestv_10) {
    Matrix_t<int> matrix1(4);
    std::istringstream input1("1 0 2 -1 -2 0 -4 2 1 0 2 -1 3 0 6 -3");
    input1 >> matrix1;

    Matrix_t<int> matrix2(4);
    
    Matrix_t<int> ans_matrix(4);

    ASSERT_TRUE(matrix1 * matrix2 == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Multiplication, Subtestv_11) {
    Matrix_t<int> matrix(1, 3);
    std::istringstream input("-2 -3 4");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(1, 3);
    std::istringstream ans_input("-6 -9 12");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix * 3 == ans_matrix);
}

TEST(Multiplication, Subtestv_12) {
    Matrix_t<int> matrix(10);
    
    Matrix_t<int> ans_matrix(10);

    ASSERT_TRUE(matrix * 3 == ans_matrix);
}

TEST(Multiplication, Subtestv_13) {
    Matrix_t<int> matrix(10);
    matrix.getIdentityMatrix();
    
    Matrix_t<int> ans_matrix(10);

    ASSERT_TRUE(matrix * 0 == ans_matrix);
}

TEST(Multiplication, Subtestv_14) {
    Matrix_t<int> matrix(3);
    std::istringstream input("1 1 1 1 1 1 1 1 1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("2 2 2 2 2 2 2 2 2");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix * 2 == ans_matrix);
}

TEST(Multiplication, Subtestv_15) {
    Matrix_t<double> matrix(2);
    std::istringstream input("2 0 0 2");
    input >> matrix;
    
    Matrix_t<double> ans_matrix(2);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix * 0.5 == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Division, Subtestv_1) {
    Matrix_t<int> matrix(100);
    
    Matrix_t<int> ans_matrix(100);

    ASSERT_TRUE(matrix / 10297436 == ans_matrix);
}

TEST(Division, Subtestv_2) {
    Matrix_t<int> matrix(3);
    std::istringstream input("2 2 2 2 2 2 2 2 2");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("1 1 1 1 1 1 1 1 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix / 2 == ans_matrix);
}

TEST(Division, Subtestv_3) {
    Matrix_t<int> matrix(3);
    matrix.getIdentityMatrix();
    
    Matrix_t<int> ans_matrix(3);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix / 1 == ans_matrix);
}

TEST(Division, Subtestv_4) {
    Matrix_t<double> matrix(3);
    std::istringstream input("1 1 1 1 1 1 1 1 1");
    input >> matrix;
    
    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("2 2 2 2 2 2 2 2 2");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix / 0.5 == ans_matrix);
}

TEST(Division, Subtestv_5) {
    Matrix_t<int> matrix(4, 1);
    std::istringstream input("6 3 12 -9");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(4, 1);
    std::istringstream ans_input("2 1 4 -3");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix / 3 == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Addition, Subtestv_1) {
    Matrix_t<int> matrix1(2);
    std::istringstream input1("1 2 3 4");
    input1 >> matrix1;

    Matrix_t<int> matrix2(2);
    std::istringstream input2("2 4 6 8");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(2);
    std::istringstream ans_input("3 6 9 12");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 + matrix2 == ans_matrix);
}

TEST(Addition, Subtestv_2) {
    Matrix_t<int> matrix1(1);
    std::istringstream input1("1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(1);
    std::istringstream input2("-1");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(1);

    ASSERT_TRUE(matrix1 + matrix2 == ans_matrix);
}

TEST(Addition, Subtestv_3) {
    Matrix_t<int> matrix1(100);

    Matrix_t<int> matrix2(100);
    
    Matrix_t<int> ans_matrix(100);

    ASSERT_TRUE(matrix1 + matrix2 == ans_matrix);
}

TEST(Addition, Subtestv_4) {
    Matrix_t<int> matrix1(1000);
    matrix1.getIdentityMatrix();

    Matrix_t<int> matrix2(1000);
    
    Matrix_t<int> ans_matrix(1000);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix1 + matrix2 == ans_matrix);
}

TEST(Addition, Subtestv_5) {
    Matrix_t<int> matrix(3);
    std::istringstream input("1 1 1 1 1 1 1 1 1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("2 2 2 2 2 2 2 2 2");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix + matrix == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Substraction, Subtestv_1) {
    Matrix_t<int> matrix1(2);
    std::istringstream input1("1 2 3 4");
    input1 >> matrix1;

    Matrix_t<int> matrix2(2);
    std::istringstream input2("2 4 6 8");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(2);
    std::istringstream ans_input("-1 -2 -3 -4");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 - matrix2 == ans_matrix);
}

TEST(Substraction, Subtestv_2) {
    Matrix_t<int> matrix1(1);
    std::istringstream input1("1");
    input1 >> matrix1;

    Matrix_t<int> matrix2(1);
    std::istringstream input2("-1");
    input2 >> matrix2;
    
    Matrix_t<int> ans_matrix(1);
    std::istringstream ans_input("2");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix1 - matrix2 == ans_matrix);
}

TEST(Substraction, Subtestv_3) {
    Matrix_t<int> matrix1(100);

    Matrix_t<int> matrix2(100);
    
    Matrix_t<int> ans_matrix(100);

    ASSERT_TRUE(matrix1 - matrix2 == ans_matrix);
}

TEST(Substraction, Subtestv_4) {
    Matrix_t<int> matrix1(1000);
    matrix1.getIdentityMatrix();

    Matrix_t<int> matrix2(1000);
    
    Matrix_t<int> ans_matrix(1000);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix1 - matrix2 == ans_matrix);
}

TEST(Substraction, Subtestv_5) {
    Matrix_t<int> matrix(3);
    std::istringstream input("1 1 1 1 1 1 1 1 1");
    input >> matrix;
    
    Matrix_t<int> ans_matrix(3);

    ASSERT_TRUE(matrix - matrix == ans_matrix);
}

// ----------------------------------------------------------------------------------------

TEST(Inverse, Subtestv_1) {
    Matrix_t<double> matrix(3);
    std::istringstream input("2 5 7 6 3 4 5 -2 -3");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("1 -1 1 -38 41 -34 27 -29 24");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_2) {
    Matrix_t<double> matrix(2);
    std::istringstream input("1 2 3 4");
    input >> matrix;

    Matrix_t<double> ans_matrix(2);
    std::istringstream ans_input("-2 1 1.5 -0.5");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_3) {
    Matrix_t<double> matrix(3);
    std::istringstream input("1 2 3 0 1 4 5 6 0");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("-24 18 5 20 -15 -4 -5 4 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_4) {
    Matrix_t<double> matrix(3);
    std::istringstream input("3 0 2 2 0 -2 0 1 1");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("0.2 0.2 0 -0.2 0.3 1 0.2 -0.3 0");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_5) {
    Matrix_t<double> matrix(3);
    std::istringstream input("2 0 1 0 -3 -1 -2 4 0");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("2 2 1.5 1 1 1 -3 -4 -3");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_6) {
    Matrix_t<double> matrix(3);
    std::istringstream input("1 -1 1 2 1 1 1 1 2");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("0.2 0.6 -0.4 -0.6 0.2 0.2 0.2 -0.4 0.6");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_7) {
    Matrix_t<double> matrix(3);
    matrix.getIdentityMatrix();

    Matrix_t<double> ans_matrix(3);
    ans_matrix.getIdentityMatrix();

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_8) {
    Matrix_t<double> matrix(2);
    std::istringstream input("5 3 3 2");
    input >> matrix;

    Matrix_t<double> ans_matrix(2);
    std::istringstream ans_input("2 -3 -3 5");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_9) {
    Matrix_t<double> matrix(3);
    std::istringstream input("3 -4 5 2 -3 1 3 -5 -1");
    input >> matrix;

    Matrix_t<double> ans_matrix(3);
    std::istringstream ans_input("-8 29 -11 -5 18 -7 1 -3 1");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

TEST(Inverse, Subtestv_10) {
    Matrix_t<double> matrix(4);
    std::istringstream input("1 2 3 4 2 3 1 2 1 1 1 -1 1 0 -2 -6");
    input >> matrix;

    Matrix_t<double> ans_matrix(4);
    std::istringstream ans_input("22 -6 -26 17 -17 5 20 -13 -1 0 2 -1 4 -1 -5 3");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix.inverse() == ans_matrix);
}

#endif // BASE_OPERATORS_H_