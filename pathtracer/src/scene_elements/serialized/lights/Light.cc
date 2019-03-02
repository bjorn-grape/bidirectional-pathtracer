#include "Light.hh"

Light::Light()
        : color_(Vector3D<uint8_t>())
          , intensity_(1) {}

Light::Light(float intensity, const Vector3D<uint8_t> &color)
        : color_(color)
          , intensity_(intensity) {}

float Light::getIntensity_() const {
    return intensity_;
}

void Light::setIntensity_(float intensity_) {
    Light::intensity_ = intensity_;
}

const Vector3D<uint8_t> &Light::getColor_() const {
    return color_;
}

void Light::setColor_(const Vector3D<uint8_t> &color_) {
    Light::color_ = color_;
}

