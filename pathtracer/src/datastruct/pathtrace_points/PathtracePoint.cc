#include "PathtracePoint.hh"

PathtracePoint::PathtracePoint(Vector3D<float> &position, Vector3D<float> &color,
                               Vector3D<float> &normal, size_t depth_, size_t point_number_,
                               KDTree &kd_tree)
        : position_(position)
          , color_(color)
          , normal_of_touched_element_(normal)
          , depth_(depth_)
          , point_number_(point_number_)
          , kdTree_(kd_tree) {}

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




PathtracePoint::PathtracePoint(const Vector3D<float> &position, const Vector3D<float> &color,
                               const Vector3D<float> &normal, const size_t depth,
                               const size_t point_number, const KDTree &kd_tree)
        : position_(position)
          , color_(color)
          , normal_of_touched_element_(normal)
          , depth_(depth)
          , point_number_(point_number)
          , kdTree_(kd_tree){
}

