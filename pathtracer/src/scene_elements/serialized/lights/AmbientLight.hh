#pragma once
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>
#include <stdint-gcc.h>
#include "Vector3D.hh"
#include "Light.hh"

class AmbientLight : public Light {
public:
    AmbientLight();

    AmbientLight(float intensity, const Vector3D<float> &color);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::base_class<Light>(this));
    }
};


