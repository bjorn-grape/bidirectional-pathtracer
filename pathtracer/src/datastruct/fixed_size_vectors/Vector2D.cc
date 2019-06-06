//
// Created by bjorn on 26/02/19.
//
#include "Vector2D.hh"
template<>
bool Vector2D<float>::operator==(const Vector2D<float> &rhs) const {
    return std::abs(x_ - rhs.x_) < constants::EPSILON &&
           std::abs(y_ - rhs.y_) < constants::EPSILON;
}