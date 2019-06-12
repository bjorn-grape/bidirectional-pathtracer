#pragma once

#include "BoundingBox.hh"
#include "../../tools/Tools.hh"


inline float BoundingBox::getMinX() const {
    return min[0];
}

inline float BoundingBox::getMinY() const {
    return min[1];
}

inline float BoundingBox::getMinZ() const {
    return min[2];
}

inline float BoundingBox::getMaxX() const {
    return max[0];
}

inline float BoundingBox::getMaxY() const {
    return max[1];
}

inline float BoundingBox::getMaxZ() const {
    return max[2];
}

inline Vector3D<float> BoundingBox::GetDimensions() const {
    return Vector3D(getMaxX() - getMinX(),
                    getMaxY() - getMinY(), getMaxZ() - getMinZ());
}

inline void BoundingBox::readVector3DinMin(const Vector3D<float> &vector3D) {
    min[0] = vector3D.getX();
    min[1] = vector3D.getY();
    min[2] = vector3D.getZ();
}

inline void BoundingBox::readVector3DinMax(const Vector3D<float> &vector3D) {
    max[0] = vector3D.getX();
    max[1] = vector3D.getY();
    max[2] = vector3D.getZ();
}

inline SplitAxis::Axis BoundingBox::GetLargestDimension() const {
    auto dim = GetDimensions();
    return Tools<float>::maxIndexOfThree(dim.getX(), dim.getY(), dim.getZ());
}


inline SplitAxis::Axis BoundingBox::GetSmallestDimension() const {
    auto dim = GetDimensions();
    return Tools<float>::minIndexOfThree(dim.getX(), dim.getY(), dim.getZ());
}

inline void BoundingBox::setExtremumFromPolygonList(const std::vector<Polygon> &polygons) {
    auto vmin = Vector3D<float>(INFINITY, INFINITY, INFINITY);
    auto vmax = Vector3D<float>(-INFINITY, -INFINITY, -INFINITY);
    for (const auto &polygon: polygons) {
        Vector3D<float> mean = polygon.meanVertices();
        vmin.replaceMyContentBy(vmin.minOfTwoCoordinates(mean));
        vmax.replaceMyContentBy(vmax.maxOfTwoCoordinates(mean));
    }
    readVector3DinMin(vmin - toleranceBoundaries * vmin.abs());
    readVector3DinMax(vmax + toleranceBoundaries * vmin.abs());
}


inline float *BoundingBox::operator[](const int &i) {
    return i ? max : min;
}


