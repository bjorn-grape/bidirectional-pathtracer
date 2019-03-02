#ifndef PATHTRACER_LIGHT_HH
#define PATHTRACER_LIGHT_HH

#include <cereal/access.hpp>
#include <cereal/cereal.hpp>
#include <cstdint>
#include "../../fixed_size_vectors/Vector3D.hh"

class Light {
public:
    Light();
    Light(float intensity, const Vector3D<uint8_t>& color);


public:

    float getIntensity_() const;

    void setIntensity_(float intensity_);

    const Vector3D<uint8_t> &getColor_() const;

    void setColor_(const Vector3D<uint8_t> &color_);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(color_), CEREAL_NVP(intensity_));
    }

protected:
    Vector3D<uint8_t> color_;
    float intensity_;
};


#endif //PATHTRACER_LIGHT_HH
