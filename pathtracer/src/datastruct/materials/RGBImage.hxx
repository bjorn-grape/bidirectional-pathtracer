#pragma once

#include "RGBImage.hh"

inline Vector3D<uint8_t> RGBImage::getPixel(const unsigned &lineIndex, const unsigned &columnIndex) {
    unsigned index = (lineIndex * width_ + columnIndex) * 3;
    return Vector3D<uint8_t>(pixels_[index], pixels_[index + 1], pixels_[index + 2]);
}

inline uint8_t
RGBImage::getPixelComponent(const unsigned &lineIndex, const unsigned &columnIndex,
                            const RGBImage::component &type) {
    unsigned index = (lineIndex * width_ + columnIndex) * 3;
    return pixels_[index + static_cast<unsigned>(type)];
}

inline Vector3D<uint8_t> RGBImage::getPixelInIndexPercentage(const float &linePercent, const float &columnPercent) {
    if(linePercent > 1.f || linePercent < 0.f || columnPercent > 1.f || columnPercent < 0.f )
        throw new std::invalid_argument("RGB image percentage < 0 or RGB image percentage > 1");
    unsigned lineIndex = static_cast<unsigned>(linePercent * width_);
    unsigned columnIndex = static_cast<unsigned>(columnPercent * height_);
    unsigned index = (lineIndex * width_ + columnIndex) * 3;
    return Vector3D<uint8_t>(pixels_[index], pixels_[index + 1], pixels_[index + 2]);
}

inline uint8_t
RGBImage::getPixelComponentInIndexPercentage(const float &linePercent, const float &columnPercent,
                                             const RGBImage::component &type) {
    if(linePercent > 1.f || linePercent < 0.f || columnPercent > 1.f || columnPercent < 0.f )
        throw new std::invalid_argument("RGB image percentage < 0 or RGB image percentage > 1");
    unsigned lineIndex = static_cast<unsigned>(linePercent * width_);
    unsigned columnIndex = static_cast<unsigned>(columnPercent * height_);
    unsigned index = (lineIndex * width_ + columnIndex) * 3;
    return pixels_[index + static_cast<unsigned>(type)];
}
