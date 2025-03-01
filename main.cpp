#include "matrix.h"

int main() {
    try {
        size_t N;
        std::cin >> N;
        if (!std::cin.good()) {
            throw std::invalid_argument("\n Invalid input for matrix size");
        }

        Matrix_t<double> matrix(N);
        std::cin >> matrix;

        std::cout << matrix.BareissAlgorithm() << std::endl;
    } catch (const MatrixException& e) {
        std::cerr << "Matrix error: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Input error: " << e.what() << std::endl;
    }
}