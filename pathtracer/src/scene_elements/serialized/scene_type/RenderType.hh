#pragma  once

#include <cereal/cereal.hpp>

class RenderType {
public:
    enum render_algo {
        pathtracer,
        raytracer
    };

    RenderType() = default;

    RenderType(render_algo type, unsigned int pass_number_, unsigned int light_depth_,
               unsigned int light_number_per_depth_, unsigned int camera_depth_,
               unsigned int camera_number_per_depth_);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(type), CEREAL_NVP(pass_number_),
           CEREAL_NVP(light_depth_), CEREAL_NVP(light_number_per_depth_),
           CEREAL_NVP(camera_depth_), CEREAL_NVP(camera_number_per_depth_));
    }

private:
    render_algo type = pathtracer;
// In case of pathtracer
    unsigned pass_number_ = 1;
    unsigned light_depth_ = 1;
public:
    render_algo getType() const;

    unsigned int getPass_number() const;

    unsigned int getLight_depth() const;

    unsigned int getLight_number_per_depth() const;

    unsigned int getCamera_depth() const;

    unsigned int getCamera_number_per_depth() const;

private:
    unsigned light_number_per_depth_ = 1;
    unsigned camera_depth_ = 1;
    unsigned camera_number_per_depth_ = 1;
};

