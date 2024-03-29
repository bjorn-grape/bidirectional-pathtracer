#include <vector>
#include "Ray.hh"


Ray::Ray(const Vector3D<float> &position, const Vector3D<float> &direction)
        : direction_(direction)
          , position_(position) {
    invdirection_ = Vector3D<float>(1, 1, 1) / direction_;
    sign_[0] = (invdirection_.getX() < 0);
    sign_[1] = (invdirection_.getY() < 0);
    sign_[2] = (invdirection_.getZ() < 0);
}


const Vector3D<float> &Ray::getPosition() const {
    return position_;
}

void Ray::setPosition(const Vector3D<float> &position) {
    Ray::position_ = position;
}

const Vector3D<float> &Ray::getDirection() const {
    return direction_;
}

void Ray::setOrientation(const Vector3D<float> &direction) {
    Ray::direction_ = direction;
}


bool
Ray::intersectOneTriangle(const Vector3D<float> &v0, const Vector3D<float> &v1, const Vector3D<float> &v2,
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
    float t = f * edge2.dotproduct(q);
    if (t > constants::EPSILON) {
        intersection = position_ + direction_ * t;
        return true;
    }
    return false;
}

bool Ray::intersectOnePolygon(const std::vector<Vector3D<float>> vertices, Vector3D<float> &intersection) const {
    if (vertices.size() < 2)
        return false;
    auto v0 = vertices[0];
    auto v1 = vertices[1];

    auto N = v0.crossproduct(v1);

    float D = N.dotproduct(v0);

    float denom_t = N.dotproduct(direction_);
    if (std::abs(denom_t) < constants::EPSILON)
        return false; // means ray an plan are almost collinear
    float num_t = N.dotproduct(position_) + D;
    float t = -num_t / denom_t;
    if (t < 0)
        return false; //polygon is behind us

    for (size_t i = 0; i < vertices.size(); ++i) {
        auto v = vertices[i];
        auto E0 = vertices[(i + 1) % vertices.size()] - v;
        auto c0 = position_ - v;
        if (N.dotproduct(E0.crossproduct(c0)) < constants::EPSILON)
            return false;
    }
    intersection = position_ + direction_ * t;
    return true;
}


std::vector<Vector3D<float>> Ray::intersectAllObjects(const std::vector<Polygon> &objects) {
    std::vector<Vector3D<float>> intersections;
    for (const auto &object : objects) {
        Vector3D<float> intersect;
        bool hasIntersect;
        if (object.isTriangle())
            hasIntersect = this->intersectOneTriangle(object.getVertices()[0], object.getVertices()[1],
                                                      object.getVertices()[2], intersect);
        else
            hasIntersect = this->intersectOnePolygon(object.getVertices(), intersect);

        if ((hasIntersect))
            intersections.push_back(intersect);
    }
    return intersections;
}

const Vector3D<float> &Ray::getInvDirection() const {
    return invdirection_;
}

int *Ray::getSign() {
    return sign_;
}

bool Ray::intersect(const Polygon &poly, Vector3D<float> &intersection) const {
    if (poly.isTriangle())
        intersectOneTriangle(poly.getVertices()[0], poly.getVertices()[1],
                             poly.getVertices()[2], intersection);
    else
        intersectOnePolygon(poly.getVertices(), intersection);
}

