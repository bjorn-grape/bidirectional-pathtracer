#pragma once

#include <KDTree.hh>
#include "PathtracePoint.hh"
#include "LightPoint.hh"

class LightPoint;

class CameraPoint : public PathtracePoint {
public:
    CameraPoint();

    CameraPoint(const Vector3D<float> &position,const Vector3D<float> &color, const Vector3D<float> &normal,
                size_t depth_, size_t point_number_,const KDTree &kd_tree);

    void addToChildren(Vector3D<float> &position,
                       Vector3D<float> &color,
                       Vector3D<float> &normal,
                       size_t depth_,
                       size_t point_number_,
                       const KDTree &kd_tree);

    void gatherLightsSeen(const LightPoint &lp, Vector3D<float> &color_seen);

    std::vector<CameraPoint> getChildren() const;

private:
    std::vector<CameraPoint> children_;
};

