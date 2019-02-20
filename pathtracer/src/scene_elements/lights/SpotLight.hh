#ifndef PATHTRACER_SPOTLIGHT_HH
#define PATHTRACER_SPOTLIGHT_HH


#include "Light.hh"

class SpotLight : public Light {
public:
    float angle;
    Vector3D<float> direction;
    Vector3D<float> position;

};


#endif //PATHTRACER_SPOTLIGHT_HH
