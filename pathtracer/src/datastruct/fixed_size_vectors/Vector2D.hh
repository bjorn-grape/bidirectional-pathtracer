#pragma once
#include <stdio.h>
#include <ostream>
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>

template<typename T>
class Vector2D {
public:
    Vector2D();

    Vector2D(T x, T y);

    T getX() const;

    void setX(T x_);

    T getY() const;

    void setY(T y_);

    Vector2D<T> operator+(const Vector2D<T> &vector2D) const;

    void operator+=(const Vector2D<T> &vector2D);

    void operator+=(const T &elm);

    Vector2D<T> operator-(const Vector2D<T> &vector2D) const;

    void operator-=(const Vector2D<T> &vector2D);

    void operator-=(const T &elm);

    Vector2D<T> operator*(const Vector2D<T> &vector2D) const;

    void operator*=(const Vector2D<T> &vector2D);

    void operator*=(const T &elm);

    Vector2D<T> operator/(const Vector2D<T> &vector2D) const;

    void operator/=(const Vector2D<T> &vector2D);

    void operator/=(const T &elm);

    bool operator==(const Vector2D &rhs) const;

    bool operator!=(const Vector2D &rhs) const;

    T dotproduct(const Vector2D &rhs) const;

    T crossproduct(const Vector2D &rhs) const;


    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(x_), CEREAL_NVP(y_));
    }

private:
    T x_;
    T y_;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2D<T> &d);


#include "Vector2D.hxx"

