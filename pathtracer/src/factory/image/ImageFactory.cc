#include <string>
#include <tbb/parallel_for.h>
#include <atomic>
#include "ImageFactory.hh"


ImageFactory::ImageFactory(const Camera& cam, const Scene& scene)
        : camera_(cam)
          , scene_(scene) {
    screen_content_.reserve(cam.getScreenDimensionX() * cam.getScreenDimensionY() * 3);
}


void ImageFactory::travelScreen(unsigned current_iteration) {

    float stepx;
    float stepy;
    std::vector<float> temp_screen_content;
    unsigned total_component_nb = camera_.getScreenDimensionX() * camera_.getScreenDimensionY() * 3;
    temp_screen_content.reserve(total_component_nb);
    Vector3D<float> screenUpLeftVector;
    camera_.initPerspective(stepx, stepy, screenUpLeftVector);
    std::atomic<int> countWork = 0;
    tbb::parallel_for(size_t(0), static_cast<size_t>(camera_.getScreenDimensionY()), [&](size_t ii) {
        countWork++;
        std::cout << "computing lines :" << (float) countWork / (float) camera_.getScreenDimensionY() * 100.f << "%"
                  << std::endl;
        long i = (ii - camera_.getScreenDimensionY() / 2);
        auto upOrigin = screenUpLeftVector;
        upOrigin.rotateOnX(stepy * i);
        for (unsigned jj = 0; jj < camera_.getScreenDimensionX(); ++jj) {
            long j = -(jj - camera_.getScreenDimensionX() / 2);
            auto goodRot = upOrigin;
            goodRot.rotateOnY(stepx * j);
            Ray ray = Ray(camera_.getPosition(), goodRot);
            Vector3D<float> pixel;

            // part to change between pathtracer and raytracer
            computePixel(ray, pixel);

            placePixel(ii, jj, pixel, temp_screen_content);
        }
    });
    float portion_from_temp = 1.f / (current_iteration + 1.f);
    float portion_from_original = 1.f - portion_from_temp;

    for (unsigned k = 0; k < total_component_nb; ++k) {
        screen_content_[k] = screen_content_[k] * portion_from_original
                             + temp_screen_content[k] * portion_from_temp;
    }

}


void ImageFactory::dumpToPpm(const std::string& path) {
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






