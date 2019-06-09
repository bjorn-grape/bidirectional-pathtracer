#include "DistancePolygonComparator.hh"


DistancePolygonComparator::DistancePolygonComparator(const Vector3D<float> &origin) : origin_vector_(origin) {}

bool DistancePolygonComparator::operator()(PolygonWithIntersection& a, PolygonWithIntersection& b) {
    return (a.intersection_point_ - origin_vector_).norm() < (b.intersection_point_ - origin_vector_).norm();
}



