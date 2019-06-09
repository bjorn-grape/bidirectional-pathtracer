#pragma once

//#include "Tools.hh"
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
typename Tools<T>::mapAxis Tools<T>::comparisonFunctionsMap = create_map();


