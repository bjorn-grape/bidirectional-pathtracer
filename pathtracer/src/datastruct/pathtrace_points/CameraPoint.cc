//
// Created by bjorn on 09/06/19.
//

#include "CameraPoint.hh"

const std::vector<CameraPoint> &CameraPoint::getChildren() const {
    return children_;
}

CameraPoint::CameraPoint(const Vector3D<float> &position,
                         const Vector3D<float> &color, const Vector3D<float> &normal,
                         const size_t depth_, const size_t point_number_, const KDTree &kdTree)
        : PathtracePoint(position, color, normal)
          , depth_(depth_)
          , point_number_(point_number_)
          , kdTree_(kdTree){
    setup();
}

void CameraPoint::setup() {
    if (depth_ < 1)
        return;
    for (size_t i = 0; i < point_number_; ++i) {


        Vector3D new_dir = normal_of_touched_element_.getRandomRayAccordingToDiffuseBrdf();
        Ray ray = Ray(position_, new_dir);
        Polygon res;
        bool doIntersect = kdTree_.getIntersectionPoly(ray, res);

//CameraPoint camPt = CameraPoint()
    }
}
