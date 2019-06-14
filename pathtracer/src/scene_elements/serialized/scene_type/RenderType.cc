
#include "RenderType.hh"

RenderType::RenderType(RenderType::render_algo type, unsigned int pass_number_,
                       unsigned int light_depth_, unsigned int light_number_per_depth_,
                       unsigned int camera_depth_, unsigned int camera_number_per_depth_)
        : type(type), pass_number_(pass_number_), light_depth_(light_depth_), light_number_per_depth_(
        light_number_per_depth_), camera_depth_(camera_depth_), camera_number_per_depth_(camera_number_per_depth_) {}

RenderType::render_algo RenderType::getType() const {
    return type;
}

unsigned int RenderType::getPass_number() const {
    return pass_number_;
}

unsigned int RenderType::getLight_depth() const {
    return light_depth_;
}

unsigned int RenderType::getLight_number_per_depth() const {
    return light_number_per_depth_;
}

unsigned int RenderType::getCamera_depth() const {
    return camera_depth_;
}

unsigned int RenderType::getCamera_number_per_depth() const {
    return camera_number_per_depth_;
}


