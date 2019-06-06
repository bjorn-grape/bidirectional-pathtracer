#pragma once

#include <string>
#include <Camera.hh>
#include <Scene.hh>

class ImageFactory {

public:
    ImageFactory(const Camera &cam, const Scene &scene);

    void dumpToPpm(const std::string &basic_string);

    virtual void compute() = 0;

protected:

    void travelScreen();
    virtual void computePixel(const Ray &ray, Vector3D<float> &cool) const = 0;

    inline void placePixel(size_t x, size_t y, const Vector3D<float> &pixel);

    const Camera &camera_;
    const Scene &scene_;
    std::vector<uint8_t> screen_content_;

};

#include "ImageFactory.hxx"