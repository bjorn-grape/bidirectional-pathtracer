#pragma once

#include "../datastruct/SplitAxis.hh"
#include "../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../scene_elements/Polygon.hh"
#include "../datastruct/box/BoundingBox.hh"
#include "../scene_elements/Ray.hh"
#include "../parser/AllPolygonContainer.hh"

template<typename T>
class Tools {
public:
    typedef std::function<bool(Vector3D<T>, Vector3D<T>)> funcVecTor3sqToBool;
    typedef std::unordered_map<Polygon::compFactor, funcVecTor3sqToBool> mapAxis;

    inline static SplitAxis::Axis minIndexOfThree(const T &x, const T &y, const T &z);

    inline static SplitAxis::Axis maxIndexOfThree(const T &x, const T &y, const T &z);

    static void extremumPolygonList(std::vector<unsigned >& indexList, AllPolygonContainer& polygons,
            BoundingBox &box);

    static bool IntersectCubeRay(Ray ray, BoundingBox bbox);

    static Vector3D<float> originVector;

    static bool funCompareXlt(Vector3D<T> a, Vector3D<T> b) { return a.getX() < b.getX(); }

    static bool funCompareYlt(Vector3D<T> a, Vector3D<T> b) { return a.getY() < b.getY(); }

    static bool funCompareZlt(Vector3D<T> a, Vector3D<T> b) { return a.getZ() < b.getZ(); }

    static bool funCompareDistanceOrigin(Vector3D<float> a, Vector3D<float> b) {
        return std::abs((a - originVector).norm()) < std::abs((b - originVector).norm());
    }


    inline static mapAxis create_map() {
        mapAxis m;
        m[Polygon::X] = funCompareXlt;
        m[Polygon::Y] = funCompareYlt;
        m[Polygon::Z] = funCompareZlt;
        m[Polygon::distanceToOrigin] = funCompareDistanceOrigin;
        return m;
    }

    static mapAxis comparisonFunctionsMap;

};


#include "Tools.hxx"