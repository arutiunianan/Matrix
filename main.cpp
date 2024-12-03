#include "matrix/matrix.h"

int main() {
    size_t N;
    std::cin >> N;
    Matrix_t<int> matrix(N);
    std::cin >> matrix;
    matrix.getUppertriangularForm();
    std::cout << matrix;
}