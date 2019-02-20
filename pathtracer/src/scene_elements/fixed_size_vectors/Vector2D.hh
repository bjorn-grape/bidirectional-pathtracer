#ifndef PATHTRACER_VECTOR2D_HH
#define PATHTRACER_VECTOR2D_HH

template<typename T>
class Vector2D {
public:
    Vector2D();

    Vector2D(T x, T y);

    T get_X();

    T get_Y();


    void set_X(T x);

    void set_Y(T y);


private:
    T x_;
    T y_;
};


#endif //PATHTRACER_VECTOR2D_HH
