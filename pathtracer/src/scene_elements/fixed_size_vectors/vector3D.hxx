#pragma once

#include "Vector3D.hh"

template<typename T>
Vector3D<T>::Vector3D()
        : x_(0)
          , y_(0)
          , z_(0) {}

template<typename T>
Vector3D<T>::Vector3D(T x, T y, T z)
        : x_(x)
          , y_(y)
          , z_(z) {}

template<typename T>
T Vector3D<T>::getX_() const {
    return x_;
}

template<typename T>
void Vector3D<T>::setX_(T x_) {
    Vector3D::x_ = x_;
}

template<typename T>
T Vector3D<T>::getY_() const {
    return y_;
}

template<typename T>
void Vector3D<T>::setY_(T y_) {
    Vector3D::y_ = y_;
}

template<typename T>
T Vector3D<T>::getZ_() const {
    return z_;
}

template<typename T>
void Vector3D<T>::setZ_(T z_) {
    Vector3D::z_ = z_;
}

