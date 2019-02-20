#ifndef PATHTRACER_LIGHT_HH
#define PATHTRACER_LIGHT_HH


#include <cstdint>
#include "../fixed_size_vectors/Vector3D.hh"

class Light {
public:
    Light();
    Light(float intensity, Vector3D<uint8_t> color);


protected:
    float intensity_;
public:
    float getIntensity_() const;

    void setIntensity_(float intensity_);

    const Vector3D<uint8_t> &getColor_() const;

    void setColor_(const Vector3D<uint8_t> &color_);

protected:
    Vector3D<uint8_t> color_;
};


#endif //PATHTRACER_LIGHT_HH
