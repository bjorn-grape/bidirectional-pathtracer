//
// Created by bjorn on 26/02/19.
//

#include <iostream>
#include <tiff.h>
#include "Camera.hh"
#include "tbb/tbb.h"
#include "../../../color/Colors.hh"
#include "../../../datastruct/polygon_dist/PolygonDist.hh"

Camera::Camera(const Vector2D<unsigned> &screenDimension,
               const Vector3D<float> &position, const Vector3D<float> &orientation,
               const float &fovDegree)
        : fieldOfView_(fovDegree)
          , screenDimension_(screenDimension)
          , position_(position)
          , orientation_(orientation) {}

void Camera::dumpImageToPpm(std::string path) {
    std::ofstream ofstream(path);
    ofstream << "P3\n";
    ofstream << screenDimension_.getX() << " ";
    ofstream << screenDimension_.getY() << "\n";
    ofstream << "255\n";
    for (unsigned i = 0; i < screenDimension_.getY(); ++i) {
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {
            int index = (i * screenDimension_.getX() + j) * 3;
            ofstream << static_cast<int>(screen_[index]) << " ";
            ofstream << static_cast<int>(screen_[index + 1]) << " ";
            ofstream << static_cast<int>(screen_[index + 2]) << " ";
        }
        ofstream << "\n";
    }
}

Camera &Camera::operator=(const Camera &camera) {
    this->orientation_ = camera.orientation_;
    this->position_ = camera.position_;
    this->screenDimension_ = camera.screenDimension_;
    return *this;
}


void getPixelInfos(const Ray &ray, Scene &scene, Vector3D<uint8_t> &cool) {
    Vector3D<float> fff;
    std::vector<Polygon *> polygons;
    scene.kdtree.getIntersectionList(ray, polygons);
    std::vector<PolygonDist> polygonDists;
    for (const Polygon *p : polygons) {

        if (p->isTriangle())
            if (ray.intersectOneTriangle(const_cast<Vector3D<float> &>(p->getVertices()[0]),
                                         const_cast<Vector3D<float> &>(p->getVertices()[1]),
                                         const_cast<Vector3D<float> &>(p->getVertices()[2]),
                                         fff)) {

                polygonDists.emplace_back((fff - ray.getPosition()).norm(), *p);
            }
    }
    std::sort(polygonDists.begin(),polygonDists.end());
    if (!polygonDists.empty()) {
        auto color = polygonDists[0].getPolygon().getMaterial().ambient;
        cool = Vector3D<uint8_t>(color[0] * 255, color[1] * 255, color[2] * 255);
    } else
        cool = Colors::GREEN;

}

void Camera::travelScreen(Scene scene) {
    const float scaleDimension =
            static_cast<float>(screenDimension_.getY()) / static_cast<float>(screenDimension_.getX());
    float stepx;
    float stepy;
    if (scaleDimension > 1u) {
        stepx = getFieldOfViewRadian() / screenDimension_.getX();
        stepy = getFieldOfViewRadian() / screenDimension_.getY() * scaleDimension;
    } else {
        stepx = getFieldOfViewRadian() / screenDimension_.getX() / scaleDimension;
        stepy = getFieldOfViewRadian() / screenDimension_.getY();
    }

    Vector3D<float> screenUpLeftVector = orientation_;
    Vector3D<float> howToRotate = Vector3D<float>(-stepy * screenDimension_.getY() / 2.f,
                                                  -stepx * screenDimension_.getX() / 2.f,
                                                  0);
    screenUpLeftVector.rotate(howToRotate);
    screen_.reserve(screenDimension_.getX() * screenDimension_.getY() * 3);
//    for (int i = 0; i < screenDimension_.getY(); ++i) {


    tbb::parallel_for(size_t(0), static_cast<size_t>(screenDimension_.getY()), [&](size_t i) {
        auto upOrigin = screenUpLeftVector;
        upOrigin.rotateOnX(stepy * i);
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {
            auto goodRot = upOrigin;
            goodRot.rotateOnY(stepx * j);
            Ray ray = Ray(position_, goodRot);
            Vector3D<uint8_t> pixel;
            getPixelInfos(ray, scene, pixel);
            size_t index = (i * screenDimension_.getX() + j) * 3;
            screen_[index] = pixel.getX();
            screen_[index + 1] = pixel.getY();
            screen_[index + 2] = pixel.getZ();
        }
    });
//    }
}


float Camera::getFieldOfViewRadian() {
    return fieldOfView_ * constants::PI / 180.f;
}
