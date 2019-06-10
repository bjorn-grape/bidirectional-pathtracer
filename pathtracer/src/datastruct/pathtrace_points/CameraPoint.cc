#include "CameraPoint.hh"

std::vector<CameraPoint> CameraPoint::getChildren() const {
    return children_;
}

CameraPoint::CameraPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                         size_t depth_, size_t point_number_, const KDTree &kd_tree)
        : PathtracePoint(position, color, normal, depth_, point_number_, kd_tree) {}


void CameraPoint::gatherLightsSeen(const LightPoint &lp, Vector3D<float> &color_seen) {
    lp.gatherLightpointsForCamerapoint(*this, color_seen);

    if (children_.empty())
        return;

    Vector3D<float> color_sum;
    for (CameraPoint &camPoint :children_) {
        Vector3D<float> temp_color;
        camPoint.gatherLightsSeen(lp, temp_color);
        color_sum += temp_color;
    }
    color_sum /= children_.size();
    color_seen = color_seen / 2 + color_sum / 2;
}

CameraPoint::CameraPoint()
        : PathtracePoint(Vector3D<float>(), Vector3D<float>(),
                         Vector3D<float>(), 0, 0, KDTree()) {
}

void
CameraPoint::addToChildren(Vector3D<float> &position, Vector3D<float> &color, Vector3D<float> &normal, size_t depth_,
                           size_t point_number_, const KDTree &kd_tree) {
    CameraPoint camPT = CameraPoint(position, color, normal, depth_, point_number_, kd_tree);
    children_.emplace_back(camPT);
}


