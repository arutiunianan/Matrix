#ifndef UPPER_TRIANGULAR_H_
#define UPPER_TRIANGULAR_H_

#include <gtest/gtest.h>
#include "../matrix/matrix.h"

/*TEST(upperTriangularForm, Subtestv_1) {
    Matrix_t<int> matrix(3);
    std::istringstream input("1 2 3 4 5 6 7 8 9 \n");
    input >> matrix;
    matrix.getUppertriangularForm();
    
    Matrix_t<int> ans_matrix(3);
    std::istringstream ans_input("1 2 3 0 -3 -6 0 0 0 \n");
    ans_input >> ans_matrix;

    ASSERT_TRUE(matrix == ans_matrix);
}*/

#endif // UPPER_TRIANGULAR_H_
