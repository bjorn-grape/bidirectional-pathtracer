//
// Created by bjorn on 20/02/19.
//

#include "AmbientLight.hh"

AmbientLight::AmbientLight()
        : Light() {}

AmbientLight::AmbientLight(float intensity, const Vector3D<float> &color)
        : Light(intensity, color) {}
