#include "PolygonWithIntersection.hh"


PolygonWithIntersection &PolygonWithIntersection::operator=(const PolygonWithIntersection & ppp) {
    polygon = ppp.polygon;
    intersection_point_ = ppp.intersection_point_;
    return *this;
}

PolygonWithIntersection::PolygonWithIntersection(Polygon *polygon, Vector3D<float> &intersection_point_)
        : polygon(polygon), intersection_point_(intersection_point_) {}

