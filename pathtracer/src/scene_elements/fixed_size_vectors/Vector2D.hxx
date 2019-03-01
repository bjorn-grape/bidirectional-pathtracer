#pragma once

#include "Constants.hh"
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
T Vector2D<T>::getX() const {
    return x_;
}

template<typename T>
void Vector2D<T>::setX(T x_) {
    Vector2D::x_ = x_;
}

template<typename T>
T Vector2D<T>::getY() const {
    return y_;
}

template<typename T>
void Vector2D<T>::setY(T y_) {
    Vector2D::y_ = y_;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T> &vector2D) const {
    return Vector2D<T>(this->x_ + vector2D.x_, this->y_ + vector2D.y_);
}

template<typename T>
Vector2D<T> operator+(const Vector2D<T> &vector2D, const T &elm) {
    return Vector2D<T>(vector2D.x_ + elm, vector2D.y_ + elm);
}


template<typename T>
Vector2D<T> operator+(const T &elm, const Vector2D<T> &vector2D) {
    return Vector2D<T>(vector2D.x_ + elm, vector2D.y_ + elm);
}


template<typename T>
void Vector2D<T>::operator+=(const Vector2D<T> &vector2D) {
    this->x_ += vector2D.x_;
    this->y_ += vector2D.y_;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D<T> &vector2D) const {
    return Vector2D<T>(this->x_ - vector2D.x_, this->y_ - vector2D.y_);
}

template<typename T>
Vector2D<T> operator-(const Vector2D<T> &vector2D, const T &elm) {
    return Vector2D<T>(vector2D.x_ - elm, vector2D.y_ - elm);
}


template<typename T>
void Vector2D<T>::operator-=(const Vector2D<T> &vector2D) {
    this->x_ -= vector2D.x_;
    this->y_ -= vector2D.y_;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator*(const Vector2D<T> &vector2D) const {
    return Vector2D<T>(this->x_ * vector2D.x_, this->y_ * vector2D.y_);
}

template<typename T>
Vector2D<T> operator*(const Vector2D<T> &vector2D, const T &elm) {
    return Vector2D<T>(vector2D.x_ * elm, vector2D.y_ * elm);
}


template<typename T>
Vector2D<T> operator*(const T &elm, const Vector2D<T> &vector2D) {
    return Vector2D<T>(vector2D.x_ * elm, vector2D.y_ * elm);
}


template<typename T>
void Vector2D<T>::operator*=(const Vector2D<T> &vector2D) {
    this->x_ *= vector2D.x_;
    this->y_ *= vector2D.y_;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator/(const Vector2D<T> &vector2D) const {
    return Vector2D<T>(this->x_ / vector2D.x_, this->y_ / vector2D.y_);
}

template<typename T>
Vector2D<T> operator/(const Vector2D<T> &vector2D, const T &elm) {
    return Vector2D<T>(vector2D.x_ / elm, vector2D.y_ / elm);
}


template<typename T>
void Vector2D<T>::operator/=(const Vector2D<T> &vector2D) {
    this->x_ /= vector2D.x_;
    this->y_ /= vector2D.y_;
}



template<typename T>
bool Vector2D<T>::operator==(const Vector2D &rhs) const {
    return x_ == rhs.x_ &&
           y_ == rhs.y_;
}



template<typename T>
bool Vector2D<T>::operator!=(const Vector2D &rhs) const {
    return !(rhs == *this);
}

template<typename T>
void Vector2D<T>::operator+=(const T &elm) {
    x_ += elm;
    y_ += elm;
}

template<typename T>
void Vector2D<T>::operator-=(const T &elm) {
    x_ -= elm;
    y_ -= elm;
}

template<typename T>
void Vector2D<T>::operator*=(const T &elm) {
    x_ *= elm;
    y_ *= elm;
}

template<typename T>
void Vector2D<T>::operator/=(const T &elm) {
    x_ /= elm;
    y_ /= elm;
}

template<typename T>
T Vector2D<T>::dotproduct(const Vector2D &rhs) const {
    return this->x_ * rhs.x_ + this->y_ * rhs.y_;
}

template<typename T>
T Vector2D<T>::crossproduct(const Vector2D &rhs) const {
    return this->x_ * rhs.y_ - this->y_ * rhs.x_;;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2D<T> &d) {
    os << "<" << d.getX() << "," << d.getY() << ">";
    return os;
}
