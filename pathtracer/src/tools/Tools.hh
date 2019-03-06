#pragma once

#include "../datastruct/SplitAxis.hh"
#include "../scene_elements/fixed_size_vectors/Vector3D.hh"

template<typename T>
class Tools {
public:
    typedef std::function<bool(Vector3D<T>, Vector3D<T>)> funcVecTor3sqToBool;
    typedef std::unordered_map<SplitAxis::Axis, funcVecTor3sqToBool> mapAxis;

    inline static SplitAxis::Axis minIndexOfThree(const T &x, const T &y, const T &z);

    inline static SplitAxis::Axis maxIndexOfThree(const T &x, const T &y, const T &z);


    static bool funCompareXlt(Vector3D<T> a, Vector3D<T> b) { return a.getX() < b.getX(); }

    static bool funCompareYlt(Vector3D<T> a, Vector3D<T> b) { return a.getY() < b.getY(); }

    static bool funCompareZlt(Vector3D<T> a, Vector3D<T> b) { return a.getZ() < b.getZ(); }

    inline static mapAxis create_map()
    {
        mapAxis m;
        m[SplitAxis::X] = funCompareXlt;
        m[SplitAxis::Y] = funCompareYlt;
        m[SplitAxis::Z] = funCompareZlt;
        return m;
    }

    static mapAxis comparisonFunctionsMap;

};


#include "Tools.hxx"