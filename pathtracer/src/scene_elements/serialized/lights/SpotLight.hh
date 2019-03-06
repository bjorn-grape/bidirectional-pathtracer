#pragma once

#include "Light.hh"
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>


class SpotLight : public Light {
public:
    SpotLight() = default;

    float getAngle() const;

    void setAngle(float angle);

    const Vector3D<float> &getDirection() const;

    void setDirection(const Vector3D<float> &direction);

    const Vector3D<float> &getPosition() const;

    void setPosition(const Vector3D<float> &position);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::base_class<Light>(this), CEREAL_NVP(direction_),
           CEREAL_NVP(position_));
    }

private:
    Vector3D<float> direction_;
    Vector3D<float> position_;
    float angle_;

};


