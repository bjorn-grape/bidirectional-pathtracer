#include <string>
#include <tbb/parallel_for.h>
#include "ImageFactory.hh"


ImageFactory::ImageFactory(const Camera &cam, const Scene &scene)
        : camera_(cam)
          , scene_(scene) {
    screen_content_.reserve(cam.getScreenDimensionX() * cam.getScreenDimensionY() * 3);
}


void ImageFactory::travelScreen() {

    float stepx;
    float stepy;
    Vector3D<float> screenUpLeftVector;
    camera_.initPerspective(stepx, stepy, screenUpLeftVector);

    tbb::parallel_for(size_t(0), static_cast<size_t>(camera_.getScreenDimensionY()), [&](size_t i) {
        auto upOrigin = screenUpLeftVector;
        upOrigin.rotateOnX(stepy * i);
        for (unsigned j = 0; j < camera_.getScreenDimensionX(); ++j) {
            auto goodRot = upOrigin;
            goodRot.rotateOnY(stepx * j);
            Ray ray = Ray(camera_.getPosition(), goodRot);
            Vector3D<float> pixel;

            // part to change between pathtracer and raytracer
            computePixel(ray, pixel);

            placePixel(i, j, pixel);
        }
    });
}


void ImageFactory::dumpToPpm(const std::string &path) {
    std::ofstream ofstream(path);
    ofstream << "P3\n";
    ofstream << camera_.getScreenDimensionX() << " ";
    ofstream << camera_.getScreenDimensionY() << "\n";
    ofstream << "255\n";
    for (unsigned i = 0; i < camera_.getScreenDimensionY(); ++i) {
        for (unsigned j = 0; j < camera_.getScreenDimensionX(); ++j) {
            size_t index = (i * camera_.getScreenDimensionX() + j) * 3;
            ofstream << static_cast<int>( 255.f * screen_content_[index] ) << " ";
            ofstream << static_cast<int>( 255.f * screen_content_[index + 1]  ) << " ";
            ofstream << static_cast<int>( 255.f * screen_content_[index + 2] ) << " ";
        }
        ofstream << "\n";
    }
}






