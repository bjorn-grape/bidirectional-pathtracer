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

    void setX_(T x_);

    T getY_() const;

    void setY_(T y_);

    T getZ_() const;

    void setZ_(T z_);

private:
    T y_;
    T z_;
};


#endif //PATHTRACER_VECTOR3D_HH
