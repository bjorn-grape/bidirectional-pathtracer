//
// Created by claus on 26/02/2019.
//

#ifndef PATHTRACER_LUMINANCEINPOINT_HH
#define PATHTRACER_LUMINANCEINPOINT_HH

#include <vector>
#include "fixed_size_vectors/Vector3D.hh"
#include "Polygon.hh"

class LuminanceInPoint {
public:
    bool shadow_ray(Vector3D<float> p1, Vector3D<float> p2);
    float luminance_in_point(Vector3D<float> p1);
    float luminance();

private:
    std::vector<Vector3D<float>> ray_viewer_;
    std::vector<Vector3D<float>> ray_light_;
    std::vector<Polygon> objects_;
};


#endif //PATHTRACER_LUMINANCEINPOINT_HH
g