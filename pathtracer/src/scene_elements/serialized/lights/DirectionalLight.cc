#include "DirectionalLight.hh"

const Vector3D<float> &DirectionalLight::getDirection() const {
    return direction_;
}

DirectionalLight::DirectionalLight(const Vector3D<float> &direction_,
                                   float intensity, const Vector3D<float> &color)
        : Light(intensity, color), direction_(direction_) {}

void DirectionalLight::setDirection(const Vector3D<float> &direction) {
    DirectionalLight::direction_ = direction;

}

DirectionalLight::DirectionalLight(const Vector3D<float> &direction)
        : direction_(direction) {}



