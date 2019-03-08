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

    if (x == val)
        return SplitAxis::X;
    if (y == val)
        return SplitAxis::Y;
    if (z == val)
        return SplitAxis::Z;

    return SplitAxis::none;
}

template<typename T>
void Tools<T>::extremumPolygonList(std::vector<unsigned> &indexList, AllPolygonContainer &polygons,
                                   BoundingBox &box) {
    box.min = std::make_shared<Vector3D<float>>(INFINITY, INFINITY, INFINITY);
    box.max = std::make_shared<Vector3D<float>>(-INFINITY, -INFINITY, -INFINITY);
    for (unsigned i = 0; i < polygons.size(); i++) {
        Vector3D<float> mean = polygons[i].meanVertices();
        box.min->replaceMyContentBy(box.min->minOfTwoCoordinates(mean));
        box.max->replaceMyContentBy(box.max->maxOfTwoCoordinates(mean));
    }
}

template<typename T>
bool Tools<T>::IntersectCubeRay(Ray ray, BoundingBox bbox) {

    Vector3D<float> p = ray.getPosition();
    Vector3D<float> d = ray.getOrientation();
    Vector3D<float> &bbmin = *(bbox.min);
    Vector3D<float> &bbmax = *(bbox.max);

    float tmin = 0.0f;
    // set to -FLT_MAX to get first hit on line
    float tmax = MAXFLOAT;
    // set to max distance ray can travel (for segment)
    // For all three slabs
    for (int i = 0; i < 3; i++) {
        float boxMin;
        float boxMax;
        float pos;
        float dir;
        switch (i) {
            case 0:
                boxMin = bbmin.getX();
                boxMax = bbmax.getX();
                pos = p.getX();
                dir = d.getX();
                break;
            case 1:
                boxMin = bbmin.getY();
                boxMax = bbmax.getY();
                pos = p.getY();
                dir = d.getY();
                break;
            default:
                boxMin = bbmin.getZ();
                boxMax = bbmax.getZ();
                pos = p.getZ();
                dir = d.getZ();
                break;
        }
        if (std::abs(dir) < constants::EPSILON) {
            // Ray is parallel to slab. No hit if origin not within slab
            if (pos < boxMin || pos > boxMax)
                return false;
        } else {
            // Compute intersection t value of ray with near and far plane of slab
            float ood = 1.0f / d.getX();
            float t1 = (boxMin - pos) * ood;
            float t2 = (boxMax - pos) * ood;
            // Make t1 be intersection with near plane, t2 with far plane
            if (t1 > t2)
                std::swap(t1, t2);
            // Compute the intersection of slab intersection intervals
            tmin = std::max(t1, tmin);
            tmax = std::max(t2, tmax);
            // Exit with no collision as soon as slab intersection becomes empty
            if (tmin > tmax)
                return false;
        }
    }
    // Ray intersects all 3 slabs. Return point (q) and intersection t value (tmin)
    //intersect = p + d * tmin;
    return true;
}

template<typename T>
typename Tools<T>::mapAxis Tools<T>::comparisonFunctionsMap = create_map();

template<typename T>
Vector3D<float> Tools<T>::originVector = Vector3D<float>(NAN, NAN, NAN);