#pragma once

#include <Vector3D.hh>
#include <polygon/PolygonWithIntersection.hh>

class DistancePolygonComparator {
public:

    explicit DistancePolygonComparator(const Vector3D<float>& origin);

    bool operator()(PolygonWithIntersection& a, PolygonWithIntersection &b);

private:
    const Vector3D<float>& origin_vector_;
};

