#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <cstring>

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
    T *matrix_;

public:
    Matrix_t(size_t rows, size_t cols);
    Matrix_t(size_t rows);
    ~Matrix_t();

    size_t getRows() const {
        return rows_;
    }
    size_t getCols() const {
        return cols_;
    }

    T           &operator[](size_t index)                const;
    bool        operator==(Matrix_t<T> &compared_matrix) const;
    Matrix_t<T> operator*(Matrix_t &matrix)              const;
    Matrix_t<T> operator*(T value)                       const;
    Matrix_t<T> operator/(T value)                       const;
    Matrix_t<T> operator+(Matrix_t &matrix)              const;
    Matrix_t<T> operator-(Matrix_t &matrix)              const;

    Matrix_t<T> inverse() const;
    Matrix_t<T> transpose() const;

    T *getIdentityMatrix();

    //T blockGaussMethod(size_t block_size);
    //T *getUppertriangularForm();

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
    rows_(rows), cols_(cols){
    matrix_ = new T[rows * cols];
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            matrix_[cols * i + j] = 0;
        }
    }
}

template<typename T>
Matrix_t<T>::Matrix_t(size_t rows):
    Matrix_t(rows, rows) {}

template<typename T>
Matrix_t<T>::~Matrix_t() {
    delete[] matrix_;
}

template<typename T>
T *Matrix_t<T>::getIdentityMatrix() {
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            matrix_[cols_ * i + j] = (i == j) ? 1 : 0;
        }
    }
    return matrix_;
}

//-------------------Implementation of the Gauss block method-------------------

/*template<typename T>
T Matrix_t<T>::blockGaussMethod(size_t block_size) {
    if(rows_ != cols_) {
        std::cout << "The determinant is considered only for square matrices";
        return 0;
    }
    size_t blocks_count = rows_ / block_size;
    size_t elems_outside_blocks = rows_ % block_size;
    for (size_t block_ind = 1; block_ind <= blocks_count; ++block_ind) {

    }
}

template<typename T>
T *Matrix_t<T>::getUppertriangularForm() {
    T *cur_row = new T[rows_];
    for(size_t i = 0; i < cols_ - 1; ++i) {
        std::memcpy(cur_row, matrix_ + rows_ * i, sizeof(T) * rows_);

        T i_elem = cur_row[i];
        for(size_t j = 0; j < rows_; ++j) {
            cur_row[j] = cur_row[j] / i_elem;
        }

        for(size_t j = i + 1; j < cols_; ++j) {
            T i_elem = matrix_[j * rows_ + i];
            for(size_t k = 0; k < rows_; ++k) {
                matrix_[j * rows_ + k] = matrix_[j * rows_ + k] - i_elem * cur_row[k];
            }
        }
    }
}*/

//-------------------------------Matrix operators-------------------------------

template<typename T>
T &Matrix_t<T>::operator[](size_t index) const {
    return matrix_[index];
}

template<typename T>
bool Matrix_t<T>::operator==(Matrix_t<T> &compared_matrix) const {
    if(rows_ != compared_matrix.getRows()) {
        return false;
    }
    if(cols_ != compared_matrix.getCols()) {
        return false;
    }

    for(size_t i = 0; i < getSize(); ++i) {
        if(matrix_[i] != compared_matrix[i]) {
            return false;
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
                mulMatrix[matrix.getCols() * i + j] += matrix_[cols_ * i + k] * matrix[matrix.getCols() * k + j];
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
            mulMatrix[cols_ * i + j] = matrix_[cols_ * i + j] * value;
        }
    }
    return mulMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator/(T value) const {
    Matrix_t divMatrix(rows_, cols_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            divMatrix[cols_ * i + j] = matrix_[cols_ * i + j] / value;
        }
    }
    return divMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator+(Matrix_t &matrix) const {
    Matrix_t addMatrix(rows_, matrix.getCols());
    for(size_t i = 0; i < matrix.getCols(); ++i) {
        for(size_t j = 0; j < rows_; ++j) {
            addMatrix[cols_ * i + j] = matrix_[cols_ * i + j] + matrix[cols_ * i + j];
        }
    }
    return addMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::operator-(Matrix_t &matrix) const {
    Matrix_t subMatrix(rows_, matrix.getCols());
    for(size_t i = 0; i < matrix.getCols(); ++i) {
        for(size_t j = 0; j < rows_; ++j) {
            subMatrix[cols_ * i + j] = matrix_[cols_ * i + j] - matrix[cols_ * i + j];
        }
    }
    return subMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::inverse() const {
    Matrix_t inverseMatrix(rows_, cols_);
    T *indentityMatrix = inverseMatrix.getIdentityMatrix();

    T *bufmatrix_ = new T[rows_ * cols_];
    std::memcpy(bufmatrix_, matrix_, sizeof(T) * rows_ * cols_);
    for(size_t i = 0; i < rows_; ++i) {
        T i_elem = bufmatrix_[cols_ * i + i];
        for(size_t j = 0; j < cols_; ++j) {
            bufmatrix_[cols_ * i + j] = bufmatrix_[cols_ * i + j] / i_elem;
            indentityMatrix[cols_ * i + j] = indentityMatrix[cols_ * i + j] / i_elem;
        }

        for(size_t j = 0; j < rows_; ++j) {
            if(j == i) {
                continue;
            }

            T i_elem = bufmatrix_[j * cols_ + i];
            for(size_t k = 0; k < cols_; ++k) {
                bufmatrix_[cols_ * j + k] = bufmatrix_[cols_ * j + k] - i_elem * bufmatrix_[cols_ * i + k];
                indentityMatrix[cols_ * j + k] = indentityMatrix[cols_ * j + k] - i_elem * indentityMatrix[cols_ * i + k];
            }
        }
    }

    delete []bufmatrix_;
    return inverseMatrix;
}

template<typename T>
Matrix_t<T> Matrix_t<T>::transpose() const {
    Matrix_t transposeMatrix(cols_, rows_);
    for(size_t i = 0; i < rows_; ++i) {
        for(size_t j = 0; j < cols_; ++j) {
            transposeMatrix[rows_ * j + i] = matrix_[cols_ * i + j];
        }
    }
    return transposeMatrix;
}

//-----------------------------Matrix input output-----------------------------

template<typename T>
std::istream &operator>>(std::istream &istr, Matrix_t<T> &matrix)
{
	for(size_t i = 0; i < matrix.rows_; ++i) {
		for(size_t j = 0; j < matrix.cols_; ++j)  {
    		istr >> std::ws;
			istr >> matrix[matrix.cols_ * i + j];
            std::cout << std::endl << std::endl << matrix.cols_ * i + j << std::endl << std::endl;
    	}
	}
	return istr;
}

template<typename T>
std::ostream &operator<<(std::ostream &ostr, const Matrix_t<T> &matrix)
{
    ostr << std::endl;
    ostr << matrix.rows_ << " " << matrix.cols_ << std::endl;
	for(size_t i = 0; i < matrix.rows_; ++i) {
		for(size_t j = 0; j < matrix.cols_; ++j)  {
            ostr << matrix[matrix.cols_ * i + j] << " ";
        }
        ostr << std::endl;
	}
	return ostr;
}

#endif // #define MATRIX_H_