//
// Created by bjorn on 13/03/19.
//

#include "PolygonDist.hh"

bool PolygonDist::operator<(const PolygonDist &rhs) const {
    return distance < rhs.distance;
}

bool PolygonDist::operator>(const PolygonDist &rhs) const {
    return rhs < *this;
}

bool PolygonDist::operator<=(const PolygonDist &rhs) const {
    return !(rhs < *this);
}

bool PolygonDist::operator>=(const PolygonDist &rhs) const {
    return !(*this < rhs);
}

PolygonDist::PolygonDist(float distance, const Polygon &polygon)
        : distance(distance), polygon(polygon) {}

const Polygon &PolygonDist::getPolygon() const {
    return polygon;
}
