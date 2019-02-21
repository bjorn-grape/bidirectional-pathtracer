#ifndef PATHTRACER_VECTOR2D_HH
#define PATHTRACER_VECTOR2D_HH

#include <stdio.h>
#include <ostream>

template<typename T>
class Vector2D {
public:
    Vector2D();

    Vector2D(T x, T y);

    T getX_() const;

    void setX_(T x_);

    T getY_() const;

    void setY_(T y_);

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

private:
    T x_;
    T y_;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2D<T> &d);


#include "Vector2D.hxx"

#endif //PATHTRACER_VECTOR2D_HH
