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
T Vector3D<T>::getY_() const {
    return y_;
}

template<typename T>
T Vector3D<T>::getZ_() const {
    return z_;
}

template<typename T>
void Vector3D<T>::setX_(T x) {
    x_ = x;
}

template<typename T>
void Vector3D<T>::setY_(T y) {
    y_ = y;
}

template<typename T>
void Vector3D<T>::setZ_(T z) {
    z_ = z;
}

template<typename T>
bool Vector3D<T>::operator==(const Vector3D &rhs) const {
    return getX_() == rhs.getX_() &&
           getY_() == rhs.getY_() &&
           getZ_() == rhs.getZ_();
}

template<typename T>
bool Vector3D<T>::operator!=(const Vector3D &rhs) const {
    return !(rhs == *this);
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(getX_() + vector3D.getX_(), getY_() + vector3D.getY_(), getZ_() + vector3D.getZ_());
}

template<typename T>
Vector3D<T> operator+(const T &elm, const Vector3D<T> &vector3D) {
    return Vector3D<T>(vector3D.getX_() + elm, vector3D.getY_() + elm, vector3D.getZ_() + elm);
}


template<typename T>
Vector3D<T> Vector3D<T>::operator+(const T &elm) const {
    return Vector3D<T>(getX_() + elm, getY_() + elm, getZ_() + elm);
}


template<typename T>
void Vector3D<T>::operator+=(const Vector3D<T> &vector3D) {
    *this = *this + vector3D;
}

template<typename T>
void Vector3D<T>::operator+=(const T &elm) {
    *this = *this + elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator-(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(getX_() - vector3D.getX_(), getY_() - vector3D.getY_(), getZ_() - vector3D.getZ_());
}


template<typename T>
Vector3D<T> Vector3D<T>::operator-(const T &elm) const {
    return Vector3D<T>(getX_() - elm, getY_() - elm, getZ_() - elm);
}


template<typename T>
void Vector3D<T>::operator-=(const Vector3D<T> &vector3D) {
    *this = *this - vector3D;
}

template<typename T>
void Vector3D<T>::operator-=(const T &elm) {
    *this = *this - elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(getX_() * vector3D.getX_(), getY_() * vector3D.getY_(), getZ_() * vector3D.getZ_());
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*(const T &elm) const {
    return Vector3D<T>(getX_() * elm, getY_() * elm, getZ_() * elm);
}

template<typename T>
Vector3D<T> operator*(const T &elm, const Vector3D<T> &vector3D) {
    return Vector3D<T>(vector3D.getX_() * elm, vector3D.getY_() * elm, vector3D.getZ_() * elm);
}

template<typename T>
void Vector3D<T>::operator*=(const Vector3D<T> &vector3D) {
    *this = *this * vector3D;
}

template<typename T>
void Vector3D<T>::operator*=(const T &elm) {
    *this = *this * elm;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator/(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(getX_() / vector3D.getX_(), getY_() / vector3D.getY_(), getZ_() / vector3D.getZ_());
}

template<typename T>
Vector3D<T> Vector3D<T>::operator/(const T &elm) const {
    return Vector3D<T>(getX_() / elm, getY_() / elm, getZ_() / elm);
}

template<typename T>
void Vector3D<T>::operator/=(const Vector3D<T> &vector3D) {
    *this = *this / vector3D;
}

template<typename T>
void Vector3D<T>::operator/=(const T &elm) {
    *this = *this / elm;
}

template<typename T>
T Vector3D<T>::dotproduct(const Vector3D &vector3D) const {
    return getX_() * vector3D.getX_() + getY_() * vector3D.getY_() + getZ_() * vector3D.getZ_();
}

template<typename T>
Vector3D<T> Vector3D<T>::crossproduct(const Vector3D &vector3D) const {
    return Vector3D(getY_() * vector3D.getZ_() - getZ_() * vector3D.getY_(),
                    getZ_() * vector3D.getX_() - getX_() * vector3D.getZ_(),
                    getX_() * vector3D.getY_() - getY_() * vector3D.getX_());
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3D<T> &d) {
    os << "<" << d.getX_() << "," << d.getY_() << "," << d.getZ_() << ">";
    return os;
}