#include "CameraPoint.hh"

std::vector<CameraPoint> CameraPoint::getChildren() const {
    return children_;
}

CameraPoint::CameraPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                         const size_t depth_, const size_t point_number_, const KDTree &kd_tree)
        : PathtracePoint(position, color, normal, depth_, point_number_, kd_tree) {}

void
CameraPoint::addToChildren(const Vector3D<float> &position, const Vector3D<float> &color,
                           const Vector3D<float> &normal, const size_t depth_,
                           const size_t point_number_, const KDTree &kd_tree) {
    CameraPoint camPT = CameraPoint(position, color, normal, depth_, point_number_, kd_tree);
    children_.emplace_back(camPT);
}


