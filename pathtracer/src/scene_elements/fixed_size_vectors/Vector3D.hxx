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
T Vector3D<T>::getX() const {
    return x_;
}


template<typename T>
T Vector3D<T>::getY() const {
    return y_;
}

template<typename T>
T Vector3D<T>::getZ() const {
    return z_;
}

template<typename T>
void Vector3D<T>::setX(T x) {
    x_ = x;
}

template<typename T>
void Vector3D<T>::setY(T y) {
    y_ = y;
}

template<typename T>
void Vector3D<T>::setZ(T z) {
    z_ = z;
}

template<typename T>
bool Vector3D<T>::operator==(const Vector3D &rhs) const {
    return getX_() == rhs.getX() &&
           getY_() == rhs.getY() &&
           getZ_() == rhs.getZ();
}

template<typename T>
bool Vector3D<T>::operator!=(const Vector3D &rhs) const {
    return !(rhs == *this);
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D<T> &vector3D) const {
    return Vector3D<T>(getX() + vector3D.getX(), getY() + vector3D.getY(), getZ() + vector3D.getZ());
}

template<typename T>
Vector3D<T> operator+(const T &elm, const Vector3D<T> &vector3D) {
    return Vector3D<T>(vector3D.getX() + elm, vector3D.getY() + elm, vector3D.getZ() + elm);
}


template<typename T>
Vector3D<T> Vector3D<T>::operator+(const T &elm) const {
    return Vector3D<T>(getX() + elm, getY() + elm, getZ() + elm);
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
    return Vector3D<T>(getX() - vector3D.getX(), getY() - vector3D.getY(), getZ() - vector3D.getZ());
}


template<typename T>
Vector3D<T> Vector3D<T>::operator-(const T &elm) const {
    return Vector3D<T>(getX() - elm, getY() - elm, getZ() - elm);
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
    return Vector3D<T>(getX() * vector3D.getX(), getY() * vector3D.getY(), getZ() * vector3D.getZ());
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*(const T &elm) const {
    return Vector3D<T>(getX() * elm, getY() * elm, getZ() * elm);
}

template<typename T>
Vector3D<T> operator*(const T &elm, const Vector3D<T> &vector3D) {
    return Vector3D<T>(vector3D.getX() * elm, vector3D.getY() * elm, vector3D.getZ() * elm);
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
    return Vector3D<T>(getX() / vector3D.getX(), getY() / vector3D.getY(), getZ() / vector3D.getZ());
}

template<typename T>
Vector3D<T> Vector3D<T>::operator/(const T &elm) const {
    return Vector3D<T>(getX() / elm, getY() / elm, getZ() / elm);
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
    return getX() * vector3D.getX() + getY() * vector3D.getY() + getZ() * vector3D.getZ();
}

template<typename T>
Vector3D<T> Vector3D<T>::crossproduct(const Vector3D &vector3D) const {
    return Vector3D(getY() * vector3D.getZ() - getZ() * vector3D.getY(),
                    getZ() * vector3D.getX() - getX() * vector3D.getZ(),
                    getX() * vector3D.getY() - getY() * vector3D.getX());
}

template<typename T>
float Vector3D<T>::angleRadian(const Vector3D &vector3D) const {
    auto dotprod = *this->dotproduct(vector3D);
    auto normprod = *this->norm() * vector3D.norm();
    return std::acos(dotprod / normprod);
}

template<typename T>
float Vector3D<T>::angleDegree(const Vector3D &vector3D) const {
    return angleRadian(vector3D) * constants::PI / static_cast<float>(180);
}


template<typename T>
T Vector3D<T>::norm() const {
    return std::sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}


template<typename T>
void Vector3D<T>::rotateOnX(const float &angle) {
    setY_(getY_() * std::cos(angle) + getZ_() * std::sin(angle));
    setZ_(- getY_() * std::sin(angle) + getZ_() * std::cos(angle));
}

template<typename T>
void Vector3D<T>::rotateOnY(const float &angle) {
    setX(getX() * std::cos(angle) + getZ() * std::sin(angle));
    setZ(- getX() * std::sin(angle) + getZ() * std::cos(angle));
}

template<typename T>
void Vector3D<T>::rotate(Vector2D<float> vector2D) {
    rotateOnX(vector2D.getX());
    rotateOnY(vector2D.getY());
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3D<T> &d) {
    os << "<" << static_cast<float>(d.getX()) << ","
       << static_cast<float>(d.getY()) << ","
       << static_cast<float>(d.getZ()) << ">";
    return os;
}