#pragma once

#include "Vector2D.hh"
#include "Constants.hh"

#include <ostream>
#include <cmath>

template<typename T>
class Vector3D {
public:
    Vector3D();
    Vector3D(T x, T y, T z);

    T getX() const;
    void setX(T x);
    T getY() const;
    void setY(T y);
    T getZ() const;
    void setZ(T z);


    bool operator==(const Vector3D &rhs) const;
    bool operator!=(const Vector3D &rhs) const;
    Vector3D<T> operator+(const Vector3D<T> &vector3D) const;
    Vector3D<T> operator+(const T &elm) const;
    void operator+=(const Vector3D<T> &vector3D);
    void operator+=(const T &elm);
    Vector3D<T> operator-(const Vector3D<T> &vector3D) const;
    Vector3D<T> operator-(const T &elm) const;
    void operator-=(const Vector3D<T> &vector3D);
    void operator-=(const T &elm);
    Vector3D<T> operator*(const Vector3D<T> &vector3D) const;
    Vector3D<T> operator*(const T &elm) const;
    void operator*=(const Vector3D<T> &vector3D);
    void operator*=(const T &elm);
    Vector3D<T> operator/(const Vector3D<T> &vector3D) const;
    Vector3D<T> operator/(const T &elm) const;
    void operator/=(const Vector3D<T> &vector3D);
    void operator/=(const T &elm);

    T dotproduct(const Vector3D &vector3D) const;

    Vector3D crossproduct(const Vector3D &vector3D) const;

    T norm() const;

    float angleRadian(const Vector3D &vector3D) const;

    float angleDegree(const Vector3D &vector3D) const;

    void rotate(Vector3D<float> vector3D);

    void rotateOnX(const float &angle);

    void rotateOnY(const float &angle);
    void rotateOnZ(const float &angle);

private:
    T x_;
    T y_;
    T z_;
};

#include "Vector3D.hxx"
