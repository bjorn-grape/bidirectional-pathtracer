#pragma once

#include "../datastruct/SplitAxis.hh"

template<typename T>
class Tools {
public:
    inline static SplitAxis::Axis minIndexOfThree(const T &x, const T &y, const T &z);

    inline static SplitAxis::Axis maxIndexOfThree(const T &x, const T &y, const T &z);
};


#include "Tools.hxx"