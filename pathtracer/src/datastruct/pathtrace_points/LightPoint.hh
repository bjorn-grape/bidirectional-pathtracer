#pragma  once

#include "PathtracePoint.hh"
#include "CameraPoint.hh"

class CameraPoint;

class LightPoint : public PathtracePoint {
public:
    LightPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
               const size_t depth_, const size_t point_number_, const KDTree &kd_tree, const Material &mat,
               const Vector3D<float> &incomming_light);


    LightPoint();

    LightPoint(const KDTree &kd_tree);

    void addToChildren(Vector3D<float> &position,
                       Vector3D<float> &color,
                       Vector3D<float> &normal,
                       size_t depth_,
                       size_t point_number_,
                       const KDTree &kd_tree,
                       const Material &touched_material,
                       const Vector3D<float> &incomming_light);

    void setup();

    void gatherLightpointsForCamerapoint(const CameraPoint &camPT, Vector3D<float> &color_res) const;

    const std::vector<LightPoint> &getChildren() const;

    void setDepth(int depth);

    void setRayNumber(int point_nb);

private:
    std::vector<LightPoint> children_;
    const Material &touched_material_;
    const Vector3D<float> &incomming_light_;
};

