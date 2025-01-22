#include "matrix/matrix.h"

int main() {
    size_t N;
    std::cin >> N;
    Matrix_t<double> matrix(N);
    std::cin >> matrix;
}