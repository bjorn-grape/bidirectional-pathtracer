#pragma once

#include "vector2D.hh"


template<typename T>
vector2D<T>::vector2D()
        : x_(0), y_(0) {}

template<typename T>
vector2D<T>::vector2D(T x, T y)
        :x_(x), y_(y) {}

template<typename T>
T vector2D<T>::get_X() {
    return x_;
}

template<typename T>
T vector2D<T>::get_Y() {
    return y_;
}

template<typename T>
void vector2D<T>::set_X(T x) {
    x_ = x;
}

template<typename T>
void vector2D<T>::set_Y(T y) {
    y_ = y;
}