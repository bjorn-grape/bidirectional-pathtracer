#pragma once

#include "SplitAxis.hh"
#include "Vector3D.hh"
#include "Polygon.hh"
#include "Ray.hh"

template<typename T>
class Tools {
public:
    typedef std::function<bool(Vector3D<T>, Vector3D<T>)> funcVecTor3sqToBool;
    typedef std::unordered_map<Polygon::compFactor, funcVecTor3sqToBool> mapAxis;

    inline static SplitAxis::Axis minIndexOfThree(const T &x, const T &y, const T &z);

    inline static SplitAxis::Axis maxIndexOfThree(const T &x, const T &y, const T &z);


//    static Vector3D<float> origin_vector_;

    static bool funCompareXlt(Vector3D<T> a, Vector3D<T> b) { return a.getX() < b.getX(); }

    static bool funCompareYlt(Vector3D<T> a, Vector3D<T> b) { return a.getY() < b.getY(); }

    static bool funCompareZlt(Vector3D<T> a, Vector3D<T> b) { return a.getZ() < b.getZ(); }


    inline static mapAxis create_map() {
        mapAxis m;
        m[Polygon::X] = funCompareXlt;
        m[Polygon::Y] = funCompareYlt;
        m[Polygon::Z] = funCompareZlt;
//        m[Polygon::distanceToOrigin] = funCompareDistanceOrigin;
        return m;
    }

    static mapAxis comparisonFunctionsMap;

};


#include "Tools.hxx"