//
// Created by bjorn on 25/02/19.
//

#ifndef PATHTRACER_MATRIX_HH
#define PATHTRACER_MATRIX_HH

#include <vector>
#include <memory>

template<typename T>
class Matrix {
public:

    const size_t getHeight_() const {
        return height_;
    }

    const size_t getWidth_() const {
        return width_;
    }

    Matrix(const size_t height, const size_t width);

    T get(const size_t height, const size_t width);

    void set(T elm, const size_t height,const size_t width);

    Matrix operator+(Matrix M);

    Matrix operator*(Matrix M);

    Matrix operator-(Matrix M);

    Matrix operator/(Matrix M);

    bool sameDim(Matrix M);

    bool operator==(const Matrix &rhs) const;

    bool operator!=(const Matrix &rhs) const {
        return !(rhs == *this);
    }


private:
    const size_t height_;
    const size_t width_;
    std::shared_ptr<std::vector<T>> vect_;
};

#include "Matrix.hxx"

#endif //PATHTRACER_MATRIX_HH
