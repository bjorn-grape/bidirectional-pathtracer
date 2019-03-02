#include "SpotLight.hh"

float SpotLight::getAngle() const {
    return angle_;
}

void SpotLight::setAngle(float angle) {
    SpotLight::angle_ = angle;
}

const Vector3D<float> &SpotLight::getDirection() const {
    return direction_;
}

void SpotLight::setDirection(const Vector3D<float> &direction) {
    SpotLight::direction_ = direction;
}

const Vector3D<float> &SpotLight::getPosition() const {
    return position_;
}

void SpotLight::setPosition(const Vector3D<float> &position) {
    SpotLight::position_ = position;
}
