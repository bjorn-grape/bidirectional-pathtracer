#pragma once
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>
#include <cstdint>
#include "Vector3D.hh"

class Light {
public:
    Light();
    Light(float intensity, const Vector3D<float>& color);


public:

    float getIntensity_() const;

    void setIntensity_(float intensity_);

    const Vector3D<float> &getColor_() const;

    void setColor_(const Vector3D<float> &color_);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(color_), CEREAL_NVP(intensity_));
    }

protected:
    Vector3D<float> color_;
    float intensity_;
};


