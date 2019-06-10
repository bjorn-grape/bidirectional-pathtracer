#include "CameraPoint.hh"

std::vector<CameraPoint> CameraPoint::getChildren() const {
    return children_;
}

CameraPoint::CameraPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                         size_t depth_, size_t point_number_, const KDTree &kd_tree)
        : PathtracePoint(position, color, normal, depth_, point_number_, kd_tree) {
    setup();
}


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
        : CameraPoint(Vector3D<float>(), Vector3D<float>(),
                      Vector3D<float>(), 0, 0, KDTree()) {
}

//void
//CameraPoint::addToChildren(Vector3D<float> &position, Vector3D<float> &color, Vector3D<float> &normal, size_t depth_,
//                           size_t point_number_, const KDTree &kd_tree) {
//    CameraPoint camPT = CameraPoint(position, color, normal, depth_, point_number_, kd_tree);
//    children_.emplace_back(camPT);
//}

void
CameraPoint::addToChildren(Vector3D<float> &position, Vector3D<float> &color, Vector3D<float> &normal, size_t depth_,
                           size_t point_number_, const KDTree &kd_tree) {
    CameraPoint camPT = CameraPoint(position, color, normal, depth_, point_number_, kd_tree);
    children_.emplace_back(camPT);
}

void CameraPoint::setup() {

    if (depth_ < 1)
        return;
    for (size_t i = 0; i < point_number_; ++i) {


        Vector3D new_dir = normal_of_touched_element_.getRandomRayAccordingToDiffuseBrdf();
        Ray ray = Ray(position_, new_dir);
        std::vector<PolygonWithIntersection> list_res;
        kdTree_.getIntersectionList(ray, list_res);
        // no intersection, go next
        if (list_res.empty())
            continue;
        // here one gets the intersection of the first polygon and go back
        // a bit in order not to be behind the polygon
        Vector3D<float> intersectionPt = list_res[0].intersection_point_ - (new_dir * constants::BIGEPSILON);
        Polygon poly = *list_res[0].polygon;
        Vector3D<float> color_res = Vector3D(poly.getMaterial().diffuse) * color_;
        auto normalAt = poly.getNormalAt(intersectionPt);
        addToChildren(intersectionPt, color_res,
                      normalAt,
                      depth_ - 1, point_number_, kdTree_);
    }
}

