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

void LightPoint::gatherLightpointsForCamerapoint(const CameraPoint &camPT, Vector3D<float> &color_res) const {
    auto direction = getPosition() - camPT.getPosition();
    Ray ray = Ray(camPT.getPosition(), direction);
    std::vector<PolygonWithIntersection> polyIntersect;
    kdTree_.getIntersectionList(ray, polyIntersect);
    color_res = camPT.getDiffuseColor() * getDiffuseColor();
    if (!polyIntersect.empty()) {
        Vector3D<float> firstInter = polyIntersect[0].intersection_point_;
        if ((camPT.getPosition() - firstInter).norm() < direction.norm()) {
            // polygon is blocking view, maybe change it later with transparency
            color_res = Vector3D(0.f, 0.f, 0.f);
        }
    }

    if (children_.empty())
        return;
    Vector3D<float> colorSum;
    for (auto lightPT : children_) {
        Vector3D<float> colorTmp;
        lightPT.gatherLightpointsForCamerapoint(camPT, colorTmp);
        colorSum += colorTmp;
    }
    colorSum /= children_.size();
    color_res = color_res / 2 + colorSum / 2;
}
