#include "PathtracePoint.hh"

PathtracePoint::PathtracePoint(const Vector3D<float> &position,
                               const Vector3D<float> &color,
                               const Vector3D<float> &normal)
        : position_(position)
          , color_(color)
          , normal_of_touched_element_(normal) {}


const Vector3D<float> &PathtracePoint::getPosition() const {
    return position_;
}

void PathtracePoint::setPosition(const Vector3D<float> &position) {
    PathtracePoint::position_ = position;
}

const Vector3D<float> &PathtracePoint::getDiffuseColor() const {
    return color_;
}

void PathtracePoint::setDiffuseColor(const Vector3D<float> &diffuse_color) {
    PathtracePoint::color_ = diffuse_color;
}

const Vector3D<float> &PathtracePoint::getNormalOfTouchedElement() const {
    return normal_of_touched_element_;
}

void PathtracePoint::setNormalOfTouchedElement(const Vector3D<float> &normal_of_touched_element) {
    PathtracePoint::normal_of_touched_element_ = normal_of_touched_element;
}


