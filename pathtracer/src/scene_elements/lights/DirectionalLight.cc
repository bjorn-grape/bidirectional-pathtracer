#include "DirectionalLight.hh"

const Vector3D<float> &DirectionalLight::getDirection() const {
    return direction;
}

void DirectionalLight::setDirection(const Vector3D<float> &direction) {
    DirectionalLight::direction = direction;
}

DirectionalLight::DirectionalLight(const Vector3D<float> &direction)
        : direction(direction) {}

DirectionalLight::DirectionalLight(float intensity, const Vector3D<uint8_t> &color,
                                   const Vector3D<float> &direction)
        : Light(intensity, color)
          , direction(direction) {}

