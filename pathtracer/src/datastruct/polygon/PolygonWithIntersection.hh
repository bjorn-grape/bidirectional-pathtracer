#pragma once

#include "Polygon.hh"

struct PolygonWithIntersection {


    Polygon* polygon;

    PolygonWithIntersection(Polygon *polygon, Vector3D<float> &intersection_point_);
    PolygonWithIntersection& operator=(const PolygonWithIntersection&);

    Vector3D<float> intersection_point_;
};


