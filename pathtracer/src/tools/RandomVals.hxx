#pragma  once

#include "RandomVals.hh"

float RandomVals::getRandomNumberUniformZeroCentered(const float& val) {
    float rdn1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    rdn1 -= 0.5f;
    rdn1 *= val;
    return rdn1;
}
