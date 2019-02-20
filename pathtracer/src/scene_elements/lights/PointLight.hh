#ifndef PATHTRACER_POINT_LIGHT_HH
#define PATHTRACER_POINT_LIGHT_HH


#include "Light.hh"

class PointLight : public Light {
    Vector3D<float> position;
    float radius;
};


#endif //PATHTRACER_POINT_LIGHT_HH
