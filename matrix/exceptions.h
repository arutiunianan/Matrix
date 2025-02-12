#ifndef EXEPTION_H_
#define EXEPTION_H_

#include <stdexcept>
#include <string>

class MatrixException: public std::runtime_error {
public:
    explicit MatrixException(const std::string& message) 
        : std::runtime_error(message) {}
};

class DimensionMismatch: public MatrixException {
public:
    explicit DimensionMismatch(): 
        MatrixException("\n Dimension Mismatch") {}
};

class DevisionByZero: public MatrixException {
public:
    explicit DevisionByZero(): 
        MatrixException("\n Division by Zero") {}
};

class NonSquareMatrix: public MatrixException {
public:
    explicit NonSquareMatrix(): 
        MatrixException("\n Non-Square Matrix") {}
};

class DeterminantIsZero: public MatrixException {
public:
    explicit DeterminantIsZero(): 
        MatrixException("\n Determinant is Zero") {}
};

#endif // #define EXEPTION_H_