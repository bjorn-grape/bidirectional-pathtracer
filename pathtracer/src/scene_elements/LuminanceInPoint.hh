//
// Created by claus on 26/02/2019.
//

#pragma once

#include <vector>

#include "fixed_size_vectors/Vector3D.hh"
#include "Polygon.hh"
#include "Ray.hh"

class LuminanceInPoint {
public:
    //Verify that there is no objects between the point p1 and the point p2
    bool IsShadowRay(Vector3D<float> p1, Vector3D<float> p2);
    //Return all the shadow ray of point p
    std::vector<Vector3D<float>> allShadowRays(Vector3D<float> p);
    //Compute luminance on point p with the shadow ray
    void luminanceOnePoint(Vector3D<float> p); //call AllShadowRays for point p and compute is luminance
    //Compute luminance in all viewer intersection point
    void luminanceAllPoint();

private:
    std::vector<Vector3D<float>> ray_viewer_;
    std::vector<Vector3D<float>> ray_light_;
    std::vector<Polygon> objects_;
};
