#pragma once

#include <KDTree.hh>
#include "PathtracePoint.hh"

class CameraPoint : public PathtracePoint {

public:

    CameraPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                const size_t depth_, const size_t point_number_, const KDTree & kdTree);


    const std::vector<CameraPoint> &getChildren() const;

private:
    void setup();

    const size_t point_number_;
    std::vector<CameraPoint> children_;
    const size_t depth_;
    const KDTree& kdTree_;
};

