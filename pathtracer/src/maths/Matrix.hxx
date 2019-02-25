#pragma once

#include "Matrix.hh"

template<typename T>
bool Matrix<T>::operator==(const Matrix &rhs) const {
    if (height_ != rhs.height_ || width_ != rhs.width_)
        return false;
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            if (vect_[width_ * i + j] != rhs.vect_[width_ * i + j])
                return false;
        }
    }
    return true;
}

template<typename T>
Matrix<T>::Matrix(const size_t height, const size_t width)
        :height_(height)
         , width_(width)
         , vect_(std::make_shared(new std::vector<T>())) {
    throw new std::Exception("NOT IMPLEMENTED!");
}

template<typename T>
T Matrix<T>::get(const size_t height, const size_t width) {
    if (height > height_ || width > width_)
        throw new std::Exception("Incorrect Matrix Dimension.");
    return vect_[height, width];
}

template<typename T>
void Matrix<T>::set(T elm, const size_t height, const size_t width) {

}

template<typename T>
Matrix Matrix<T>::operator+(Matrix M) {
    return Matrix(0, 0);
}

template<typename T>
Matrix Matrix<T>::operator*(Matrix M) {
    return Matrix(0, 0);
}

template<typename T>
Matrix Matrix<T>::operator-(Matrix M) {
    return Matrix(0, 0);
}

template<typename T>
Matrix Matrix<T>::operator/(Matrix M) {
    return Matrix(0, 0);
}

template<typename T>
bool Matrix<T>::sameDim(Matrix M) {
    return false;
}


