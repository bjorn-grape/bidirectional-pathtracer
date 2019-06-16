#pragma once

#include "Vector2D.hh"
#include "Constants.hh"

#include <ostream>
#include <cmath>
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>

template<typename T>
class Vector3D {
public:
    Vector3D();

    Vector3D(const T *array);

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

    Vector3D<float> power(const float &val) const;

    T dotproduct(const Vector3D &vector3D) const;

    Vector3D crossproduct(const Vector3D &vector3D) const;

    T norm() const;

    float angleRadian(const Vector3D &vector3D) const;

    float angleDegree(const Vector3D &vector3D) const;

    void rotate(Vector3D<T> &vector3D);

    void rotateOnX(const T &angle);

    void rotateOnY(const T &angle);

    void rotateOnZ(const T &angle);

    Vector3D minOfTwoCoordinates(const Vector3D &vector3D);

    Vector3D maxOfTwoCoordinates(const Vector3D &vector3D);


    void replaceMyContentBy(const Vector3D &vector3D);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(x_), CEREAL_NVP(y_), CEREAL_NVP(z_));
    }

    Vector3D<float> getRandomRayAccordingToDiffuseBrdf();

    Vector3D<float>  getRandomRayAccordingToDiffuseBrdfLowAngle();

    Vector3D<T> abs();

    Vector3D<float> giveMirrorOutcomingRayFromIncommingRay(const Vector3D<float> incoming_direction);

private:
    T x_;
    T y_;
    T z_;
};

#include "Vector3D.hxx"
