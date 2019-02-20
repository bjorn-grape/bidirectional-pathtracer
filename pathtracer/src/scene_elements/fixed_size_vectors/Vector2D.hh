#ifndef PATHTRACER_VECTOR2D_HH
#define PATHTRACER_VECTOR2D_HH

template<typename T>
class Vector2D {
public:
    Vector2D();

    Vector2D(T x, T y);

    T getX_() const;

    void setX_(T x_);

    T getY_() const;

    void setY_(T y_);


private:
    T x_;
    T y_;
};


#endif //PATHTRACER_VECTOR2D_HH
