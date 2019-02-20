#ifndef PATHTRACER_LIGHT_HH
#define PATHTRACER_LIGHT_HH


#include <cstdint>
#include "../fixed_size_vectors/Vector3D.hh"

class Light {
public:
    float intensity;
    Vector3D<uint8_t> color;
};


#endif //PATHTRACER_LIGHT_HH
