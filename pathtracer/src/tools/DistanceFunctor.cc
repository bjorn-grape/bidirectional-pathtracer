//
// Created by bjorn on 07/03/19.
//

#include "DistanceFunctor.hh"

DistanceFunctor::DistanceFunctor(float origin)
        : origin_(origin) {}

bool DistanceFunctor::operator()(float f1, float f2) {
    return std::abs(f1 - origin_) < std::abs(f2 - origin_);
}
