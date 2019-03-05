#pragma once

#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../SplitAxis.hh"

struct BoundingBox {
    BoundingBox(Vector3D<float> mini, Vector3D<float> maxi);
    SplitAxis::Axis GetLargestDimension() const;
    Vector3D<float> GetDimensions() const;
    Vector3D<float> min;
    Vector3D<float> max;
};
