#include "LightPoint.hh"


const std::vector<LightPoint> &LightPoint::getChildren() const {
    return children_;
}

void LightPoint::gatherLightpointsForCamerapoint(const CameraPoint &camPT, Vector3D<float> &color_res) const {
    auto direction = getPosition() - camPT.getPosition();
    Ray ray = Ray(camPT.getPosition(), direction);
    std::vector<PolygonWithIntersection> polyIntersect;
    kdTree_.getIntersectionList(ray, polyIntersect);


    if (!polyIntersect.empty() &&
        (camPT.getPosition() - polyIntersect[0].intersection_point_).norm() < direction.norm()) {
        // polygon is blocking view, maybe change it later with transparency
        color_res = Vector3D(0.f, 0.f, 0.f);
    } else {
        auto Kd = camPT.getDiffuseColor();
        Vector3D<float> Ks = Vector3D(touched_material_.specular);

        auto Id = getDiffuseColor();
        auto Lm = this->getNormalOfTouchedElement() * -1;
        auto N = camPT.getNormalOfTouchedElement();
        Vector3D<float> Rm = 2.f * (Lm.dotproduct(N)) * N - Lm;
        Vector3D<float> V = ray.getDirection() * -1;
        color_res = Kd * (Lm.dotproduct(N)) * Id + (Ks * Rm.dotproduct(V)).power(2.f) * 0.05f;
    }

    float shininess = touched_material_.shininess / 1000.f;
    color_res *= (1.f - shininess);

    if (children_.empty())
        return;
    Vector3D<float> colorSum;
    for (const LightPoint &liPT : children_) {
        Vector3D<float> colorTmp;
        liPT.gatherLightpointsForCamerapoint(camPT, colorTmp);
        colorSum += colorTmp;
    }
    colorSum /= children_.size();

    color_res += colorSum * shininess;
}

LightPoint::LightPoint(const Vector3D<float> &position, const Vector3D<float> &color, const Vector3D<float> &normal,
                       const size_t depth_, const size_t point_number_, const KDTree &kd_tree, const Material &mat,
                       const Vector3D<float> &incomming_light)
        : PathtracePoint(position, color, normal, depth_, point_number_, kd_tree)
          , touched_material_(mat)
          , incomming_light_(incomming_light) {
    setup();
}

void
LightPoint::addToChildren(Vector3D<float> &position, Vector3D<float> &color, Vector3D<float> &normal, size_t depth_,
                          size_t point_number_, const KDTree &kd_tree, const Material &touched_material,
                          const Vector3D<float> &incomming_light) {
    if (color.getX() < constants::COLORMIN
        && color.getY() < constants::COLORMIN
        && color.getY() < constants::COLORMIN)
        return;
    LightPoint camPT = LightPoint(position, color, normal, depth_, point_number_, kd_tree, touched_material,
                                  incomming_light);
    children_.emplace_back(camPT);
}

LightPoint::LightPoint(const KDTree &kd_tree)
        : LightPoint(Vector3D<float>(), Vector3D<float>(), Vector3D<float>(), 0, 0, kd_tree, Material(),
                     Vector3D<float>()) {
}

void LightPoint::setDepth(int depth) {
    depth_ = depth;

}

void LightPoint::setRayNumber(int point_nb) {
    point_number_ = point_nb;

}

LightPoint::LightPoint()
        : LightPoint(Vector3D<float>(), Vector3D<float>(),
                     Vector3D<float>(), 0, 0, KDTree(), Material(), Vector3D<float>()) {}


void LightPoint::setup() {

    if (depth_ < 1)
        return;
    for (size_t i = 0; i < point_number_; ++i) {


        Vector3D new_dir = normal_of_touched_element_.getRandomRayAccordingToDiffuseBrdf();
//        float shininess = touched_material_.shininess / 1000.f;
//        if(shininess >0.7f){
//            new_dir = normal_of_touched_element_.getRandomRayAccordingToDiffuseBrdf();
//        } else{
//            new_dir = normal_of_touched_element_.giveMirrorOutcomingRayFromIncommingRay()
//        }

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
                      depth_ - 1, point_number_, kdTree_, poly.getMaterial(), new_dir);
    }
}