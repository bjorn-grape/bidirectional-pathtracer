#ifndef PATHTRACER_LIGHTS_HH
#define PATHTRACER_LIGHTS_HH


#include <stdint-gcc.h>
#include "../fixed_size_vectors/Vector3D.hh"
#include "Light.hh"

class AmbientLight : public Light {
public:
    AmbientLight();

    AmbientLight(float intensity, const Vector3D<uint8_t> &color);
};


#endif //PATHTRACER_LIGHTS_HH
