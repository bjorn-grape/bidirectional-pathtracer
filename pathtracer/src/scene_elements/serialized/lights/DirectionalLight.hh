#ifndef PATHTRACER_DIRECTIONAL_HH
#define PATHTRACER_DIRECTIONAL_HH


#include "Light.hh"
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>


class DirectionalLight : public Light {

public:
    explicit DirectionalLight(const Vector3D<float> &direction);

    DirectionalLight( const Vector3D<float> &direction_,float intensity, const Vector3D<uint8_t> &color);

    DirectionalLight() = default;

    const Vector3D<float> &getDirection() const;

    void setDirection(const Vector3D<float> &direction);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::base_class<Light>(this), CEREAL_NVP(direction_));
    }

private:
    Vector3D<float> direction_;
};


#endif //PATHTRACER_DIRECTIONAL_HH
