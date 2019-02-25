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


bool
Ray::doIntersect(Vector3D<float> &v0, Vector3D<float> &v1, Vector3D<float> &v2,
                 Vector3D<float> &intersection) const {
    auto edge1 = v1 - v0;
    auto edge2 = v2 - v0;
    auto h = direction_.crossproduct(edge2);
    auto a = edge1.dotproduct(h);
    if (a < constants::EPSILON)
        return false;    // This ray is parallel to this triangle or in the wrong side.
    float f = 1.0f / a;
    auto s = position_ - v0;
    auto u = f * (s.dotproduct(h));
    if (u < 0.0 || u > 1.0)
        return false;
    auto q = s.crossproduct(edge1);
    auto v = f * direction_.dotproduct(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dotproduct(q);
    if (t > constants::EPSILON) // ray intersection
    {
        intersection = position_ + direction_ * t;
        return true;
    } else // This means that there is a line intersection but not a ray intersection.
        return false;
}

bool Ray::doIntersectNotOpti(const Vector3D<float> v0, const Vector3D<float> v1, const Vector3D<float> v2) const {
    auto N = v0.crossproduct(v1);

    float D = N.dotproduct(v0);

    float denom_t = N.dotproduct(direction_);
    if (std::abs(denom_t) < constants::EPSILON)
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

