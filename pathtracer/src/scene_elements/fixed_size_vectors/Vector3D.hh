#ifndef PATHTRACER_VECTOR3D_HH
#define PATHTRACER_VECTOR3D_HH

template<typename T>
class Vector3D {
public:
    Vector3D();

    Vector3D(T x, T y, T z);


private:
    T x_;
public:
    T getX_() const;

    void setX_(T x);

    T getY_() const;

    void setY_(T y);

    T getZ_() const;

    void setZ_(T z);

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

private:
    T y_;
    T z_;
};

#include "Vector3D.hxx"

#endif //PATHTRACER_VECTOR3D_HH
