//
// Created by bjorn on 20/02/19.
//

#ifndef PATHTRACER_VECTOR3D_HH
#define PATHTRACER_VECTOR3D_HH

template<typename T>
class vector3D {
public:
    vector3D();

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

template<typename T>
vector3D<T>::vector3D() {

}

template<typename T>
T vector3D<T>::get_X() {
    return nullptr;
}

template<typename T>
T vector3D<T>::get_Y() {
    return nullptr;
}

template<typename T>
T vector3D<T>::get_Z() {
    return nullptr;
}

template<typename T>
void vector3D<T>::set_X(T x) {

}

template<typename T>
void vector3D<T>::set_Y(T y) {

}

template<typename T>
void vector3D<T>::set_Z(T z) {

}


#endif //PATHTRACER_VECTOR3D_HH
