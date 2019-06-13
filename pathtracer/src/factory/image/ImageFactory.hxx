#pragma once

#include "ImageFactory.hh"


inline void ImageFactory::placePixel(size_t x, size_t y, const Vector3D<float> &pixel, std::vector<float>& temp_screen_content) {
    size_t index = (x * camera_.getScreenDimensionX() + y) * 3;
    temp_screen_content[index] = pixel.getX();
    temp_screen_content[index + 1] = pixel.getY();
    temp_screen_content[index + 2] = pixel.getZ();
}