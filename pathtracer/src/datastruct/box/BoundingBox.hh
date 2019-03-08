#pragma once

#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../SplitAxis.hh"

struct BoundingBox {
    BoundingBox(Vector3D<float> mini, Vector3D<float> maxi);

    BoundingBox() = default;

    SplitAxis::Axis GetLargestDimension() const;
    SplitAxis::Axis GetSmallestDimension() const;

    Vector3D<float> GetDimensions() const;

    std::shared_ptr<Vector3D<float>> min;
    std::shared_ptr<Vector3D<float>> max;
};
