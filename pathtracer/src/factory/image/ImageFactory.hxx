#pragma once

#include "ImageFactory.hh"


inline void ImageFactory::placePixel(size_t x, size_t y, const Vector3D<float> &pixel) {
    size_t index = (x * camera_.getScreenDimensionX() + y) * 3;
    screen_content_[index] = static_cast<unsigned char>(pixel.getX());
    screen_content_[index + 1] = static_cast<unsigned char>(pixel.getY());
    screen_content_[index + 2] = static_cast<unsigned char>(pixel.getZ());
}