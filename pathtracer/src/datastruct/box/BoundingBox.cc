#include "BoundingBox.hh"
#include "../../tools/Tools.hh"

BoundingBox::BoundingBox(Vector3D<float> mini, Vector3D<float> maxi)
        : min(std::make_shared<Vector3D<float>>(mini))
          , max(std::make_shared<Vector3D<float>>(maxi)) {}

SplitAxis::Axis BoundingBox::GetLargestDimension() const {
    auto dim = GetDimensions();
    return Tools<float>::maxIndexOfThree(dim.getX(), dim.getY(), dim.getZ());
}

Vector3D<float> BoundingBox::GetDimensions() const {
    return *max - *min;
}

SplitAxis::Axis BoundingBox::GetSmallestDimension() const {
    auto dim = GetDimensions();
    return Tools<float>::minIndexOfThree(dim.getX(), dim.getY(), dim.getZ());
}
