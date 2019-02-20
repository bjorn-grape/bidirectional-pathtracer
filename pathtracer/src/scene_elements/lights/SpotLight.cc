#include "SpotLight.hh"

float SpotLight::getAngle() const {
    return angle;
}

void SpotLight::setAngle(float angle) {
    SpotLight::angle = angle;
}

const Vector3D<float> &SpotLight::getDirection() const {
    return direction;
}

void SpotLight::setDirection(const Vector3D<float> &direction) {
    SpotLight::direction = direction;
}

const Vector3D<float> &SpotLight::getPosition() const {
    return position;
}

void SpotLight::setPosition(const Vector3D<float> &position) {
    SpotLight::position = position;
}
