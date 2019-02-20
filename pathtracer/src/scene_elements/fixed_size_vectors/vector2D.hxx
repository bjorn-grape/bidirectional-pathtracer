#pragma once

#include "Vector2D.hh"


template<typename T>
Vector2D<T>::Vector2D()
        : x_(0)
          , y_(0) {}

template<typename T>
Vector2D<T>::Vector2D(T x, T y)
        :x_(x)
         , y_(y) {}

template<typename T>
T Vector2D<T>::getX_() const {
    return x_;
}

template<typename T>
void Vector2D<T>::setX_(T x_) {
    Vector2D::x_ = x_;
}

template<typename T>
T Vector2D<T>::getY_() const {
    return y_;
}

template<typename T>
void Vector2D<T>::setY_(T y_) {
    Vector2D::y_ = y_;
}

