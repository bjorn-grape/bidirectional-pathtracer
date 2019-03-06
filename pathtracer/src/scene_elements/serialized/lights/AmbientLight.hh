#pragma once
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>
#include <stdint-gcc.h>
#include "../../fixed_size_vectors/Vector3D.hh"
#include "Light.hh"

class AmbientLight : public Light {
public:
    AmbientLight();

    AmbientLight(float intensity, const Vector3D<uint8_t> &color);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::base_class<Light>(this));
    }
};


