#ifndef PATHTRACER_DIRECTIONAL_HH
#define PATHTRACER_DIRECTIONAL_HH


#include "Light.hh"

class DirectionalLight : public Light {

public:
    explicit DirectionalLight(const Vector3D<float> &direction);

    DirectionalLight(float intensity, const Vector3D<uint8_t> &color,
                     const Vector3D<float> &direction);

    const Vector3D<float> &getDirection() const;

    void setDirection(const Vector3D<float> &direction);

private:
    Vector3D<float> direction;
};


#endif //PATHTRACER_DIRECTIONAL_HH
