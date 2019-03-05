#pragma once

#include "Tools.hh"
#include <algorithm>

template<typename T>
inline SplitAxis::Axis Tools<T>::maxIndexOfThree(const T &x, const T &y, const T &z) {
    T val = std::max(std::max(x, y), z);
    int res = 0;
    res += (val == z); //if z then 4
    res <<= 1;
    res += (val == y); //if y then 2
    res <<= 1;
    res += (val == x); //if x then 1
    return static_cast<SplitAxis::Axis>(res); // else 0
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
