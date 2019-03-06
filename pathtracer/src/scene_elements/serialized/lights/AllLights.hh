#pragma  once

#include <cereal/types/vector.hpp>
#include "AmbientLight.hh"
#include "DirectionalLight.hh"
#include "PointLight.hh"
#include "SpotLight.hh"
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>

class AllLights {
public:

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(ambient_lights_), CEREAL_NVP(directional_lights_),
           CEREAL_NVP(point_lights_), CEREAL_NVP(spot_lights_));
    }

    std::vector<AmbientLight> ambient_lights_;
    std::vector<DirectionalLight> directional_lights_;
    std::vector<PointLight> point_lights_;
    std::vector<SpotLight> spot_lights_;
};


