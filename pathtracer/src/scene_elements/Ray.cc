#include "Ray.hh"


Ray::Ray(const Vector3D<float> &position_, const Vector3D<float> &orientation)
        : position_(position_), direction_(orientation) {}


const Vector3D<float> &Ray::getPosition_() const {
    return position_;
}

void Ray::setPosition_(const Vector3D<float> &position) {
    Ray::position_ = position;
}

const Vector3D<float> &Ray::getOrientation() const {
    return direction_;
}

void Ray::setOrientation(const Vector3D<float> &orientation) {
    Ray::direction_ = orientation;
}


bool Ray::doIntersect(const Vector3D<float> v0, const Vector3D<float> v1, const Vector3D<float> v2) const {
    auto N = v0.crossproduct(v1);

    float D = N.dotproduct(v0);

    float denom_t = N.dotproduct(direction_);
    if (std::abs(denom_t) < constants::Epsilon)
        return false; // means ray an plan are almost collinear
    float num_t = N.dotproduct(position_) + D;
    float t = -num_t / denom_t;
    if (t < 0)
        return false; //triangle is behind us

    auto E0 = v1 - v0;
    auto E1 = v2 - v1;
    auto E2 = v0 - v2;

    auto c0 = position_ - v0;
    auto c1 = position_ - v1;
    auto c2 = position_ - v2;

    bool b1 = N.dotproduct(E0.crossproduct(c0)) > 0;
    bool b2 = N.dotproduct(E1.crossproduct(c1)) > 0;
    bool b3 = N.dotproduct(E2.crossproduct(c2)) > 0;

    return b1 && b2 && b3;
}
