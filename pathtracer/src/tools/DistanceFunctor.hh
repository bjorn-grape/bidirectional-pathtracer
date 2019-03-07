#pragma once

#include "../scene_elements/fixed_size_vectors/Vector3D.hh"

class DistanceFunctor {
public:
    explicit DistanceFunctor(float origin);
    bool operator()(float f1, float f2);

private:
    float origin_;
};
