#pragma  once

#include "PathtracePoint.hh"

class LightPoint : public PathtracePoint {


public:
    LightPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
               const size_t depth_, const size_t point_number_, const KDTree &kd_tree);

    virtual void addToChildren(const Vector3D<float> &position,
                               const Vector3D<float> &color,
                               const Vector3D<float> &normal,
                               const size_t depth_,
                               const size_t point_number_,
                               const KDTree &kd_tree);

private:
    std::vector<LightPoint> children_;
public:
    const std::vector<LightPoint> &getChildren() const;


};

