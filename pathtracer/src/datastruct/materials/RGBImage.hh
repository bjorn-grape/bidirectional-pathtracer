#pragma once

#include <string>
#include <vector>
#include "Vector3D.hh"

class RGBImage {
public:
    enum component {
        R = 0, G = 1, B = 2
    };

    explicit RGBImage(const std::string &path);
    RGBImage() = default;

    inline Vector3D<uint8_t> getPixel(const unsigned &lineIndex, const unsigned &columnIndex);

    inline Vector3D<uint8_t> getPixelInIndexPercentage(const float &linePercent, const float &columnPercent);

    inline uint8_t getPixelComponent(const unsigned &height, const unsigned &width, const component &type);

    inline uint8_t
    getPixelComponentInIndexPercentage(const float &linePercent, const float &columnPercent, const component &type);


private:
    unsigned height_ = 0;
    unsigned width_ = 0;
    std::vector<uint8_t> pixels_;
};


