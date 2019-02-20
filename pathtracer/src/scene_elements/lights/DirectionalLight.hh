#ifndef PATHTRACER_DIRECTIONAL_HH
#define PATHTRACER_DIRECTIONAL_HH


#include "Light.hh"

class DirectionalLight : public Light {
    Vector3D<float> direction;
};


#endif //PATHTRACER_DIRECTIONAL_HH
