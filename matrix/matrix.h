#ifndef MATRIX_H_
#define MATRIX_H_

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>

#include "exceptions.h"

constexpr double epsilon = 1e-9;

template <typename T>
class Matrix_t;

template <typename T>
std::istream& operator>>(std::istream& istr, Matrix_t<T>& matrix);
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const Matrix_t<T>& matrix);

template <typename T>
class Matrix_t final {
   private:
    size_t rows_;
    size_t cols_;
    T** matrix_;

   public:
    explicit Matrix_t(size_t rows, size_t cols);
    explicit Matrix_t(size_t rows);
    Matrix_t(const Matrix_t& matrix);
    Matrix_t& operator=(const Matrix_t& matrix);
    Matrix_t(Matrix_t&& matrix) noexcept;
    Matrix_t& operator=(Matrix_t&& matrix) noexcept;
    ~Matrix_t();

    size_t getRows() const noexcept { return rows_; }
    size_t getCols() const noexcept { return cols_; }
    T& at(size_t row, size_t col) { return matrix_[row][col]; }
    const T& at(size_t row, size_t col) const { return matrix_[row][col]; }

    bool operator==(const Matrix_t<T>& matrix) const;
    Matrix_t<T> operator*(const Matrix_t& matrix) const;
    Matrix_t<T> operator*(T value) const;
    Matrix_t<T> operator/(T value) const;
    Matrix_t<T> operator+(const Matrix_t& matrix) const;
    Matrix_t<T> operator-(const Matrix_t& matrix) const;

    Matrix_t<T> inverse() const;
    Matrix_t<T> transpose() const;

    static void swap(Matrix_t<T>& a, Matrix_t<T>& b) noexcept;
    T** getIdentityMatrix();

    T BareissAlgorithm() const;
    size_t maxInCol(T** upperTriangular, size_t j) const;

   private:
    static T** allocateMatrix(size_t rows, size_t cols);
    static T** allocateMatrix(size_t rows, size_t cols, T** copymatrix);
};

//-------------------------Constructors and destructors-------------------------

template <typename T>
Matrix_t<T>::Matrix_t(size_t rows, size_t cols)
    : rows_(rows), cols_(cols), matrix_(allocateMatrix(rows, cols)) {}

template <typename T>
Matrix_t<T>::Matrix_t(size_t rows) : Matrix_t(rows, rows) {}

template <typename T>
Matrix_t<T>::Matrix_t(const Matrix_t& matrix)
    : rows_(matrix.getRows()),
      cols_(matrix.getCols()),
      matrix_(
          allocateMatrix(matrix.getRows(), matrix.getCols(), matrix.matrix_)) {}

template <typename T>
Matrix_t<T>& Matrix_t<T>::operator=(const Matrix_t& matrix) {
    if (this == &matrix) {
        return *this;
    }

    Matrix_t<T> tmp(matrix);
    swap(*this, tmp);
    return *this;
}

template <typename T>
Matrix_t<T>::Matrix_t(Matrix_t&& matrix) noexcept
    : rows_(0), cols_(0), matrix_(nullptr) {
    swap(*this, matrix);
}

template <typename T>
Matrix_t<T>& Matrix_t<T>::operator=(Matrix_t&& matrix) noexcept {
    if (this == &matrix) {
        return *this;
    }

    swap(*this, matrix);
    return *this;
}

template <typename T>
Matrix_t<T>::~Matrix_t() {
    for (size_t i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

template <typename T>
T** Matrix_t<T>::allocateMatrix(size_t rows, size_t cols) {
    T** matrix = new T*[rows];
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
        std::fill(matrix[i], matrix[i] + cols, 0);
    }

    return matrix;
}

template <typename T>
T** Matrix_t<T>::allocateMatrix(size_t rows, size_t cols, T** copymatrix) {
    T** matrix = new T*[rows];
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
        std::memcpy(matrix[i], copymatrix[i], sizeof(T) * cols);
    }

    return matrix;
}

template <typename T>
void Matrix_t<T>::swap(Matrix_t<T>& a, Matrix_t<T>& b) noexcept {
    std::swap(a.rows_, b.rows_);
    std::swap(a.cols_, b.cols_);
    std::swap(a.matrix_, b.matrix_);
}

template <typename T>
T** Matrix_t<T>::getIdentityMatrix() {
    if (rows_ != cols_) {
        throw NonSquareMatrix{};
    }

    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            matrix_[i][j] = (i == j) ? 1 : 0;
        }
    }
    return matrix_;
}

//--------------------Implementation of the Bareiss algorithm-------------------

template <typename T>
T Matrix_t<T>::BareissAlgorithm() const {
    if (rows_ != cols_) {
        throw NonSquareMatrix{};
    }

    Matrix_t upperTriangular(*this);
    T det = 1;

    for (size_t j = 0; j < rows_ - 1; ++j) {

        size_t max_ind = maxInCol(upperTriangular.matrix_, j);
        if (j != max_ind) {
            det = -det;
            std::swap(upperTriangular.matrix_[max_ind],
                      upperTriangular.matrix_[j]);
        }

        for (size_t i = j + 1; i < cols_; ++i) {
            T j_elem = upperTriangular.matrix_[i][j];
            for (size_t k = 0; k < cols_; ++k) {
                upperTriangular.matrix_[i][k] =
                    upperTriangular.matrix_[j][j] *
                        upperTriangular.matrix_[i][k] -
                    j_elem * upperTriangular.matrix_[j][k];

                if (std::abs(upperTriangular.matrix_[j][j]) < epsilon) {
                    return 0;
                }
                upperTriangular.matrix_[i][k] /= upperTriangular.matrix_[j][j];
            }
        }
    }

    for (size_t i = 0; i < rows_; ++i) {
        det *= upperTriangular.matrix_[i][i];
    }
    return det;
}

template <typename T>
size_t Matrix_t<T>::maxInCol(T** upperTriangular, size_t j) const {
    size_t max_ind = j;
    T max_val = upperTriangular[j][j];

    for (size_t i = j + 1; i < cols_; ++i) {
        if (std::abs(max_val) < std::abs(upperTriangular[i][j])) {
            max_ind = i;
            max_val = upperTriangular[i][j];
        }
    }
    return max_ind;
}

//-------------------------------Matrix operators-------------------------------

template <typename T>
bool Matrix_t<T>::operator==(const Matrix_t<T>& matrix) const {
    if (rows_ != matrix.getRows()) {
        return false;
    }
    if (cols_ != matrix.getCols()) {
        return false;
    }

    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            if (std::fabs(matrix_[i][j] - matrix.matrix_[i][j]) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::operator*(const Matrix_t& matrix) const {
    if (cols_ != matrix.getRows()) {
        throw DimensionMismatch{};
    }

    Matrix_t mulMatrix(rows_, matrix.getCols());
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < matrix.getCols(); ++j) {
            for (size_t k = 0; k < cols_; ++k) {
                mulMatrix.matrix_[i][j] += matrix_[i][k] * matrix.matrix_[k][j];
            }
        }
    }
    return mulMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::operator*(T value) const {
    Matrix_t mulMatrix(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            mulMatrix.matrix_[i][j] = matrix_[i][j] * value;
        }
    }
    return mulMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::operator/(T value) const {
    if (value == 0) {
        throw DevisionByZero{};
    }

    Matrix_t divMatrix(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            divMatrix.matrix_[i][j] = matrix_[i][j] / value;
        }
    }
    return divMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::operator+(const Matrix_t& matrix) const {
    if (rows_ != matrix.getRows() || cols_ != matrix.getCols()) {
        throw DimensionMismatch{};
    }

    Matrix_t addMatrix(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            addMatrix.matrix_[i][j] = matrix_[i][j] + matrix.matrix_[i][j];
        }
    }
    return addMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::operator-(const Matrix_t& matrix) const {
    if (rows_ != matrix.getRows() || cols_ != matrix.getCols()) {
        throw DimensionMismatch{};
    }

    Matrix_t subMatrix(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            subMatrix.matrix_[i][j] = matrix_[i][j] - matrix.matrix_[i][j];
        }
    }
    return subMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::inverse() const {
    if (std::abs(BareissAlgorithm()) < epsilon) {
        throw DeterminantIsZero{};
    }

    Matrix_t inverseMatrix(rows_, cols_);
    T** indentitymatrix_ = inverseMatrix.getIdentityMatrix();

    T** bufmatrix_ = allocateMatrix(rows_, cols_, matrix_);

    for (size_t i = 0; i < rows_; ++i) {
        T i_elem = bufmatrix_[i][i];
        for (size_t j = 0; j < cols_; ++j) {
            bufmatrix_[i][j] = bufmatrix_[i][j] / i_elem;
            indentitymatrix_[i][j] = indentitymatrix_[i][j] / i_elem;
        }

        for (size_t j = 0; j < rows_; ++j) {
            if (j == i) {
                continue;
            }

            T ji_elem = bufmatrix_[j][i];
            for (size_t k = 0; k < cols_; ++k) {
                bufmatrix_[j][k] =
                    bufmatrix_[j][k] - ji_elem * bufmatrix_[i][k];
                indentitymatrix_[j][k] =
                    indentitymatrix_[j][k] - ji_elem * indentitymatrix_[i][k];
            }
        }
    }

    for (size_t i = 0; i < rows_; ++i) {
        delete[] bufmatrix_[i];
    }
    delete[] bufmatrix_;

    return inverseMatrix;
}

template <typename T>
Matrix_t<T> Matrix_t<T>::transpose() const {
    Matrix_t transposeMatrix(cols_, rows_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            transposeMatrix.matrix_[j][i] = matrix_[i][j];
        }
    }
    return transposeMatrix;
}

//-----------------------------Matrix input output-----------------------------

template <typename T>
std::istream& operator>>(std::istream& istr, Matrix_t<T>& matrix) {
    for (size_t i = 0; i < matrix.getRows(); ++i) {
        for (size_t j = 0; j < matrix.getCols(); ++j) {
            istr >> std::ws;
            istr >> matrix.at(i, j);
            if (!istr.good()) {
                throw std::invalid_argument("\n Invalid input for matrix elem");
            }
        }
    }
    return istr;
}

template <typename T>
std::ostream& operator<<(std::ostream& ostr, const Matrix_t<T>& matrix) {
    ostr << std::endl;
    ostr << matrix.getRows() << " " << matrix.getCols() << std::endl;
    for (size_t i = 0; i < matrix.getRows(); ++i) {
        for (size_t j = 0; j < matrix.getCols(); ++j) {
            ostr << matrix.at(i, j) << " ";
        }
        ostr << std::endl;
    }
    return ostr;
}

#endif  // #define MATRIX_H_