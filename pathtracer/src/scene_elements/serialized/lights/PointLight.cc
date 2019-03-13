#include "PointLight.hh"

const Vector3D<float> &PointLight::getPosition() const {
    return position;
}

void PointLight::setPosition(const Vector3D<float> &position) {
    PointLight::position = position;
}

float PointLight::getRadius() const {
    return radius_;
}

void PointLight::setRadius(float radius) {
    PointLight::radius_ = radius;
}

PointLight::PointLight(const Vector3D<float> &position, float radius)
        : position(position)
          , radius_(radius) {}

PointLight::PointLight(float intensity, const Vector3D<float> &color,
                       const Vector3D<float> &position, float radius)
        : Light(intensity, color)
          , position(position)
          , radius_(radius) {}
