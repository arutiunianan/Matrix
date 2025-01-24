#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <cstring>
#include <cmath>

const double epsilon = 1e-9;

template<typename T>
class Matrix_t;

template<typename T> 
std::istream &operator>>(std::istream &istr, Matrix_t<T> &matrix);
template<typename T>
std::ostream &operator<<(std::ostream &ostr, const Matrix_t<T> &matrix);

template<typename T>
class Matrix_t {
private:
    size_t rows_;
    size_t cols_;
    T **matrix_;

    class Row {
    public:
        Row(T* row, size_t size) : row_(row), size_(size) {}
        T& operator[](size_t j) {
            return row_[j];
        }
        void operator*(T value) const {
            for(size_t i = 0; i < size_; ++i) {
                row_[i] = row_[i] * value;
            }
        }
        void operator/(T value) const {
            for(size_t i = 0; i < row_; ++i) {
                row_[i] = row_[i] / value;
            }
        }
    private:
        T* row_;
        size_t size_;
    };

public:
    Matrix_t(size_t rows, size_t cols);
    Matrix_t(size_t rows);
    Matrix_t(const Matrix_t &matrix);
    Matrix_t &operator=(const Matrix_t &matrix);
    Matrix_t(Matrix_t &&matrix);
    Matrix_t &operator=(Matrix_t &&matrix);
    ~Matrix_t();

    size_t getRows() const {
        return rows_;
    }
    size_t getCols() const {
        return cols_;
    }

    Row         operator[](size_t index)        const;
    bool        operator==(Matrix_t<T> &matrix) const;
    Matrix_t<T> operator*(Matrix_t &matrix)     const;
    Matrix_t<T> operator*(T value)              const;
    Matrix_t<T> operator/(T value)              const;
    Matrix_t<T> operator+(Matrix_t &matrix)     const;
    Matrix_t<T> operator-(Matrix_t &matrix)     const;

    Matrix_t<T> inverse() const;
    Matrix_t<T> transpose() const;

    T **getIdentityMatrix();

    T BareissAlgorithm();

private:
    size_t getSize() const {
        return rows_ * cols_;
    }

    friend std::ostream &operator<< <T>(std::ostream &ostr, const Matrix_t<T> &matrix);
	friend std::istream &operator>> <T>(std::istream &istr, Matrix_t<T> &matrix);
};

//-------------------------Constructors and destructors-------------------------

template<typename T>
Matrix_t<T>::Matrix_t(size_t rows, size_t cols):
    rows_(rows), cols_(cols) {
    matrix_ = new T *[rows];
    for(size_t i = 0; i < rows; ++i) {
        matrix_[i] = new T[cols];
        for(size_t j = 0; j < cols; ++j) {
            matrix_[i][j] = 0;
        }
    }
}

template<typename T>
Matrix_t<T>::Matrix_t(size_t rows):
    Matrix_t(rows, rows) {}

template<typename T>
Matrix_t<T>::Matrix_t(const Matrix_t &matrix):
    rows_(matrix.getRows()), cols_(matrix.getCols()) {
    matrix_ = new T *[rows_];
    for(size_t i = 0; i < rows_; ++i) {
        matrix_[i] = new T[cols_];
        std::memcpy(matrix_[i], matrix.matrix_[i], sizeof(T) * cols_);
    }
}

template<typename T>
Matrix_t<T> &Matrix_t<T>::operator=(const Matrix_t& matrix) {
    if (this == &matrix) {
        return *this;
    }

    rows_ = matrix.getRows();
    cols_ = matrix.getCols();
    matrix_ = new T *[rows_];
    for(size_t i = 0; i < rows_; ++i) {
        matrix_[i] = new T[cols_];
        std::memcpy(matrix_[i], matrix.matrix_[i], sizeof(T) * cols_);
    }
    return *this;
}

template<typename T>
Matrix_t<T>::Matrix_t(Matrix_t &&matrix):
    rows_(matrix.getRows()), cols_(matrix.getCols()) {
    matrix_ = matrix.matrix_;
    
    matrix.matrix_ = new T *[rows_];
    for(size_t i = 0; i < rows_; ++i) {
        matrix.matrix_[i] = new T[cols_];
        for(size_t j = 0; j < cols_; ++j) {
            matrix.matrix_[i][j] = 0;
        }
    }
}

template<typename T>
Matrix_t<T> &Matrix_t<T>::operator=(Matrix_t &&matrix) {
    if (this == &matrix) {
        return *this;
    }

    rows_ = matrix.getRows();
    cols_ = matrix.getCols();
    matrix_ = matrix.matrix_;

    matrix.matrix_ = new T *[rows_];
    for(size_t i = 0; i < rows_; ++i) {
        matrix.matrix_[i] = new T[cols_];
        for(size_t j = 0; j < cols_; ++j) {
            matrix.matrix_[i][j] = 0;
        }
    }
    return *this;
}

template<typename T>
Matrix_t<T>::~Matrix_t() {
    for (size_t i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

template<typename T>
T **Matrix_t<T>::getIdentityMatrix() {
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            matrix_[i][j] = (i == j) ? 1 : 0;
        }
    }
    return matrix_;
}

//--------------------Implementation of the Bareiss algorithm-------------------

/*template<typename T>
T Matrix_t<T>::BareissAlgorithm() {
    Matrix_t upperTriangular(*this);
    upperTriangular[0][2] = -6;
    std::cout << upperTriangular;

    return matrix_[0][0];
}*/

//-------------------------------Matrix operators-------------------------------

template<typename T>
Matrix_t<T>::Row Matrix_t<T>::operator[](size_t index) const {
    return Row(matrix_[index], cols_);
}

template<typename T>
bool Matrix_t<T>::operator==(Matrix_t<T> &matrix) const {
    if(rows_ != matrix.getRows()) {
        return false;
    }
    if(cols_ != matrix.getCols()) {
        return false;
    }

    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            if(std::fabs(matrix_[i][j] - matrix[i][j]) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator*(Matrix_t &matrix) const {
    Matrix_t mulMatrix(rows_, matrix.getCols());
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < matrix.getCols(); ++j) {
            for(size_t k = 0; k < cols_; ++k) {
                mulMatrix[i][j] += matrix_[i][k] * matrix[k][j];
            }
        }
    }
    return mulMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator*(T value) const {
    Matrix_t mulMatrix(rows_, cols_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            mulMatrix[i][j] = matrix_[i][j] * value;
        }
    }
    return mulMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator/(T value) const {
    Matrix_t divMatrix(rows_, cols_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            divMatrix[i][j] = matrix_[i][j] / value;
        }
    }
    return divMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator+(Matrix_t &matrix) const {
    Matrix_t addMatrix(rows_, cols_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            addMatrix[i][j] = matrix_[i][j] + matrix[i][j];
        }
    }
    return addMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator-(Matrix_t &matrix) const {
    Matrix_t subMatrix(rows_, cols_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            subMatrix[i][j] = matrix_[i][j] - matrix[i][j];
        }
    }
    return subMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::inverse() const {
    Matrix_t inverseMatrix(rows_, cols_);
    inverseMatrix.getIdentityMatrix();

    T **bufmatrix_ = new T *[rows_];
    for(size_t i = 0; i < rows_; ++i) {
        bufmatrix_[i] = new T[cols_];
        std::memcpy(bufmatrix_[i], matrix_[i], sizeof(T) * cols_);
    }

    for(size_t i = 0; i < rows_; ++i) {
        T i_elem = bufmatrix_[i][i];
        for(size_t j = 0; j < cols_; ++j) {
            bufmatrix_[i][j] = bufmatrix_[i][j] / i_elem;
            inverseMatrix[i][j] = inverseMatrix[i][j] / i_elem;
        }

        for(size_t j = 0; j < rows_; ++j) {
            if(j == i) {
                continue;
            }

            T i_elem = bufmatrix_[j][i];
            for(size_t k = 0; k < cols_; ++k) {
                bufmatrix_[j][k] = bufmatrix_[j][k] - i_elem * bufmatrix_[i][k];
                inverseMatrix[j][k] = inverseMatrix[j][k] - i_elem * inverseMatrix[i][k];
            }
        }
    }

    for (size_t i = 0; i < rows_; ++i) {
        delete[] bufmatrix_[i];
    }
    delete[] bufmatrix_;
    
    return inverseMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::transpose() const {
    Matrix_t transposeMatrix(cols_, rows_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            transposeMatrix[j][i] = matrix_[i][j];
        }
    }
    return transposeMatrix;
}

//-----------------------------Matrix input output-----------------------------

template<typename T>
std::istream &operator>>(std::istream &istr, Matrix_t<T> &matrix) {
	for(size_t i = 0; i < matrix.rows_; ++i) {
		for(size_t j = 0; j < matrix.cols_; ++j)  {
    		istr >> std::ws;
			istr >> matrix[i][j];
    	}
	}
	return istr;
}

template<typename T>
std::ostream &operator<<(std::ostream &ostr, const Matrix_t<T> &matrix) {
    ostr << std::endl;
    ostr << matrix.rows_ << " " << matrix.cols_ << std::endl;
    for (size_t i = 0; i < matrix.rows_; ++i) {
        for (size_t j = 0; j < matrix.cols_; ++j) {
            ostr << matrix[i][j] << " ";
        }
        ostr << std::endl;
    }
    return ostr;
}

#endif // #define MATRIX_H_