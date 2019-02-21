#pragma once

#include "Vector3D.hh"
#include <ostream>

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

template<typename T>
bool Vector3D<T>::operator==(const Vector3D &rhs) const {
    return x_ == rhs.x_ &&
           y_ == rhs.y_ &&
           z_ == rhs.z_;
}

template<typename T>
bool Vector3D<T>::operator!=(const Vector3D &rhs) const {
    return !(rhs == *this);
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(x_ + vector3D.x_, y_ + vector3D.y_, z_ + vector3D.z_);
}

template<typename T>
Vector3D<T> operator+(const T &elm, const Vector3D<T> &vector3D) {
    return Vector3D<T>(vector3D.x_ + elm, vector3D.y_ + elm, vector3D.z_ + elm);
}


template<typename T>
Vector3D<T> operator+(const Vector3D<T> &vector3D, const T &elm) {
    return Vector3D<T>(vector3D.x_ + elm, vector3D.y_ + elm, vector3D.z_ + elm);
}


template<typename T>
void Vector3D<T>::operator+=(const Vector3D<T> &vector3D) {
    x_ += vector3D.x_;
    y_ += vector3D.y_;
    z_ += vector3D.z_;
}

template<typename T>
void Vector3D<T>::operator+=(const T &elm) {
    x_ += elm;
    y_ += elm;
    z_ += elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator-(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(x_ - vector3D.x_, y_ - vector3D.y_, z_ - vector3D.z_);
}


template<typename T>
Vector3D<T> operator-(const Vector3D<T> &vector3D, const T &elm) {
    return Vector3D<T>(vector3D.x_ - elm, vector3D.y_ - elm, vector3D.z_ - elm);
}


template<typename T>
void Vector3D<T>::operator-=(const Vector3D<T> &vector3D) {
    x_ -= vector3D.x_;
    y_ -= vector3D.y_;
    z_ -= vector3D.z_;
}

template<typename T>
void Vector3D<T>::operator-=(const T &elm) {
    x_ -= elm;
    y_ -= elm;
    z_ -= elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(x_ * vector3D.x_, y_ * vector3D.y_, z_ * vector3D.z_);
}

template<typename T>
void Vector3D<T>::operator*=(const Vector3D<T> &vector3D) {
    x_ *= vector3D.x_;
    y_ *= vector3D.y_;
    z_ *= vector3D.z_;
}

template<typename T>
void Vector3D<T>::operator*=(const T &elm) {
    x_ *= elm;
    y_ *= elm;
    z_ *= elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator/(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(x_ / vector3D.x_, y_ / vector3D.y_, z_ / vector3D.z_);
}

template<typename T>
void Vector3D<T>::operator/=(const Vector3D<T> &vector3D) {
    x_ /= vector3D.x_;
    y_ /= vector3D.y_;
    z_ /= vector3D.z_;
}

template<typename T>
void Vector3D<T>::operator/=(const T &elm) {
    x_ /= elm;
    y_ /= elm;
    z_ /= elm;
}

template<typename T>
T Vector3D<T>::dotproduct(const Vector3D &vector3D) const {
    return x_ * vector3D.x_ + y_ * vector3D.y_ + z_ * vector3D.z_;
}

template<typename T>
Vector3D<T> Vector3D<T>::crossproduct(const Vector3D &vector3D) const {
    return Vector3D(y_ * vector3D.z_ - z_ * vector3D.y_,
                    z_ * vector3D.x_ - x_ * vector3D.z_,
                    x_ * vector3D.y_ - y_ * vector3D.x_);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3D<T> &d) {
    os << "<" << d.getX_() << "," << d.getY_() << "," << d.getZ_() << ">";
    return os;
}