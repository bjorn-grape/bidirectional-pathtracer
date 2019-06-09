//
// Created by bjorn on 10/06/19.
//

#include "LightPoint.hh"


LightPoint::LightPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                       const size_t depth_, const size_t point_number_, const KDTree &kd_tree)
        : PathtracePoint(position, color, normal, depth_, point_number_, kd_tree) {}

void
LightPoint::addToChildren(const Vector3D<float> &position, const Vector3D<float> &color,
                           const Vector3D<float> &normal, const size_t depth_,
                           const size_t point_number_, const KDTree &kd_tree) {
    LightPoint camPT = LightPoint(position, color, normal, depth_, point_number_, kd_tree);
    children_.emplace_back(camPT);
}

const std::vector<LightPoint> &LightPoint::getChildren() const {
    return children_;
}
