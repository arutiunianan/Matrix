#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>


template<typename T>
class Matrix_t {
    size_t rows;
    size_t cols;
    T* matrix;

public:
    Matrix_t(size_t r, size_t c);
    ~Matrix_t();
};

template<typename T>
Matrix_t<T>::Matrix_t(size_t r, size_t c):
    rows(r), cols(c){
    matrix = new int[r * c];
}

template<typename T>
Matrix_t<T>::~Matrix_t() {
    delete[] matrix;
}

#endif // #define MATRIX_H_