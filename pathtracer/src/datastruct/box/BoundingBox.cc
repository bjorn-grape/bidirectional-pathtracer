#include "BoundingBox.hh"
#include "../../tools/Tools.hh"

BoundingBox::BoundingBox(Vector3D<float> mini, Vector3D<float> maxi)
        : min(mini)
          , max(maxi) {}

SplitAxis::Axis BoundingBox::GetLargestDimension() const {
    auto dim = GetDimensions();
    return Tools<float>::maxIndexOfThree(dim.getX(), dim.getY(), dim.getZ());
}

Vector3D<float> BoundingBox::GetDimensions() const {
    return max - min;
}
