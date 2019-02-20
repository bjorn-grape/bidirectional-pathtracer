#ifndef PATHTRACER_VECTOR3D_HH
#define PATHTRACER_VECTOR3D_HH

template<typename T>
class Vector3D {
public:
    Vector3D();

    Vector3D(T x, T y, T z);

    T get_X();

    T get_Y();

    T get_Z();

    void set_X(T x);

    void set_Y(T y);

    void set_Z(T z);

private:
    T x_;
    T y_;
    T z_;
};


#endif //PATHTRACER_VECTOR3D_HH
