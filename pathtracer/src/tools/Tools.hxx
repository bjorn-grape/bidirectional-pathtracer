#pragma once

#include "Tools.hh"
#include <algorithm>

template<typename T>
inline SplitAxis::Axis Tools<T>::maxIndexOfThree(const T &x, const T &y, const T &z) {
    T val = std::max(std::max(x, y), z);

    if (x == val)
        return SplitAxis::X;
    if (y == val)
        return SplitAxis::Y;
    if (z == val)
        return SplitAxis::Z;

    return SplitAxis::none;
}

template<typename T>
inline SplitAxis::Axis Tools<T>::minIndexOfThree(const T &x, const T &y, const T &z) {
    T val = std::min(std::min(x, y), z);
    int res = 0;
    res += (val == z);
    res <<= 1;
    res += (val == y);
    res <<= 1;
    res += (val == x);
    return static_cast<SplitAxis::Axis>(res);
}

template<typename T>
void Tools<T>::extremumPolygonList(const std::vector<Polygon> &polygons, BoundingBox &box) {
    box.min = std::make_shared<Vector3D<float>>(INFINITY, INFINITY, INFINITY);
    box.max = std::make_shared<Vector3D<float>>(-INFINITY, -INFINITY, -INFINITY);
    for (const auto &polygon: polygons) {
        Vector3D<float> mean = polygon.meanVertices();
        box.min->replaceMyContentBy(box.min->minOfTwoCoordinates(mean));
        box.max->replaceMyContentBy(box.max->maxOfTwoCoordinates(mean));
    }
}

template<typename T>
bool Tools<T>::IntersectCubeRay(Ray r, BoundingBox bbox) {
    float px = r.getPosition().getX();
    float ox = r.getOrientation().getX();
    float py = r.getPosition().getY();
    float oy = r.getOrientation().getY();

    float tmin = (bbox.min->getX() - px) / ox;
    float tmax = (bbox.max->getX() - px) / ox;

    if (tmin > tmax)
        std::swap(tmin, tmax);

    float tymin = (bbox.min->getY() - py) / oy;
    float tymax = (bbox.max->getY() - py) / oy;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float pz = r.getPosition().getZ();
    float oz = r.getOrientation().getZ();

    float tzmin = (bbox.min->getZ() - pz) / oz;
    float tzmax = (bbox.max->getZ() - pz) / oz;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    return true;
}


template<typename T>
typename Tools<T>::mapAxis Tools<T>::comparisonFunctionsMap = create_map();

template<typename T>
Vector3D<float> Tools<T>::originVector = Vector3D<float>(NAN, NAN, NAN);