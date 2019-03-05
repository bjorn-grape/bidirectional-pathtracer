#pragma once

#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"

struct BoundingBox {
    BoundingBox(Vector3D<float> mini, Vector3D<float> maxi);
    Vector3D<float> min;
    Vector3D<float> max;
};
