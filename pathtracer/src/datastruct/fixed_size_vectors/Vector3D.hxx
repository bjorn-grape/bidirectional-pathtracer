#pragma once

#include "Vector3D.hh"
#include "RandomVals.hh"

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
    return getX() == rhs.getX() &&
           getY() == rhs.getY() &&
           getZ() == rhs.getZ();
}

template<>
inline bool Vector3D<float>::operator==(const Vector3D &rhs) const {
    return std::abs(getX() - rhs.getX()) < constants::EPSILON &&
           std::abs(getY() - rhs.getY()) < constants::EPSILON &&
           std::abs(getZ() - rhs.getZ()) < constants::EPSILON;
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
void Vector3D<T>::rotateOnX(const T &angle) {
    auto yy = getY() * std::cos(angle) - getZ() * std::sin(angle);
    auto zz = getY() * std::sin(angle) + getZ() * std::cos(angle);
    setY(yy);
    setZ(zz);
}

template<typename T>
void Vector3D<T>::rotateOnY(const T &angle) {
    auto xx = getX() * std::cos(angle) + getZ() * std::sin(angle);
    auto zz = -getX() * std::sin(angle) + getZ() * std::cos(angle);
    setX(xx);
    setZ(zz);
}

template<typename T>
void Vector3D<T>::rotateOnZ(const T &angle) {
    auto xx = getX() * std::cos(angle) - getY() * std::sin(angle);
    auto yy = getX() * std::sin(angle) + getY() * std::cos(angle);
    setX(xx);
    setY(yy);
}

template<typename T>
void Vector3D<T>::rotate(Vector3D<T> &vector3D) {
    rotateOnX(vector3D.getX());
    rotateOnY(vector3D.getY());
    rotateOnZ(vector3D.getZ());
}

template<typename T>
Vector3D<T> Vector3D<T>::minOfTwoCoordinates(const Vector3D &vector3D) {
    return Vector3D(std::min<T>(x_, vector3D.x_),
                    std::min<T>(y_, vector3D.y_),
                    std::min<T>(z_, vector3D.z_));

}

template<typename T>
Vector3D<T> Vector3D<T>::maxOfTwoCoordinates(const Vector3D &vector3D) {
    return Vector3D(std::max<T>(x_, vector3D.x_),
                    std::max<T>(y_, vector3D.y_),
                    std::max<T>(z_, vector3D.z_));
}

template<typename T>
void Vector3D<T>::replaceMyContentBy(const Vector3D &vector3D) {
    x_ = vector3D.x_;
    y_ = vector3D.y_;
    z_ = vector3D.z_;
}

template<typename T>
Vector3D<T>::Vector3D(const T *array) {
    x_ = array[0];
    y_ = array[1];
    z_ = array[2];
}

template<typename T>
Vector3D<float> Vector3D<T>::power(const float &val) const {
    return Vector3D<float>(std::pow(x_, val),
                           std::pow(y_, val),
                           std::pow(z_, val));
}

template<typename T>
Vector3D<float> Vector3D<T>::getRandomRayAccordingToDiffuseBrdf() {
    float rdn1 = RandomVals::getRandomNumberUniformZeroCentered(constants::PI);
    float rdn2 = RandomVals::getRandomNumberUniformZeroCentered(constants::PI);
    Vector3D<float> ff = Vector3D<float>(rdn1, rdn2, 0.f);
    return *this + ff;
}

template<typename T>
Vector3D<float>  Vector3D<T>::getRandomRayAccordingToDiffuseBrdfLowAngle() {
    float rdn1 = RandomVals::getRandomNumberUniformZeroCentered(constants::PI/1000);
    float rdn2 = RandomVals::getRandomNumberUniformZeroCentered(constants::PI/1000);
    Vector3D<float> ff = Vector3D<float>(rdn1, rdn2, 0.f);
    return *this + ff;
}

template<typename T>
Vector3D<T> Vector3D<T>::abs() {
    return Vector3D<T>(std::abs(this->getX()),std::abs(this->getY()),std::abs(this->getZ()));
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3D<T> &d) {
    os << "<" << static_cast<float>(d.getX()) << ","
       << static_cast<float>(d.getY()) << ","
       << static_cast<float>(d.getZ()) << ">";
    return os;
}