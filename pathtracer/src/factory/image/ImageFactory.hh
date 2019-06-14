#pragma once

#include <string>
#include <Camera.hh>
#include <Scene.hh>
#include <serialized/scene_type/RenderType.hh>

class ImageFactory {

public:

    ImageFactory(const Camera &cam, const Scene &scene, const RenderType &rd);

    ImageFactory(const ImageFactory &img) = default;


    virtual void dumpToPpm(const std::string &basic_string);

    virtual void compute();

    static ImageFactory* makeFactory(Camera &camera, Scene scene, RenderType type);

protected:

    virtual void travelScreen(unsigned current_iteration);

    virtual void computePixel(const Ray &ray, Vector3D<float> &cool) const;

    virtual inline void placePixel(size_t x, size_t y, const Vector3D<float> &pixel, std::vector<float> &temp_screen_content);

    const Camera &camera_;
    const RenderType &rd_;
    const Scene &scene_;
    std::vector<float> screen_content_;

};

#include "ImageFactory.hxx"