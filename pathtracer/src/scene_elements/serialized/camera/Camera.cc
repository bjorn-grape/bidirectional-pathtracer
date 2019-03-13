//
// Created by bjorn on 26/02/19.
//

#include <iostream>
#include <tiff.h>
#include "Camera.hh"
#include "tbb/tbb.h"
#include "../../../color/Colors.hh"

Camera::Camera(const float &screenDistance, const Vector2D<unsigned> &screenDimension,
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

void Camera::computeImageRaw(KDTree tree) {
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


    tbb::parallel_for(size_t(0), static_cast<size_t>(screenDimension_.getY()), [&](size_t i) {
        auto upOrigin = screenUpLeftVector;
        upOrigin.rotateOnX(stepy * i);
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {
            auto goodRot = upOrigin;
            goodRot.rotateOnY(stepx * j);
//            std::cout << "i: " << i << " j: " << j << " -> " << goodRot << std::endl;
            bool doInter = false;
            Vector3D<uint8_t> color = Colors::CYAN;
            //auto movingDir = screenUpLeftVector + Vector3D(j * stepy, i * stepx, 0.f);
            Ray r = Ray(position_, goodRot);
            Vector3D<float> fff;

            std::vector<Polygon *> polygons;

            tree.getIntersectionList(r, polygons);

            for (const Polygon *p : polygons) {

                if (p->isTriangle())
                    if (r.intersectOneTriangle(const_cast<Vector3D<float> &>(p->getVertices()[0]),
                                               const_cast<Vector3D<float> &>(p->getVertices()[1]),
                                               const_cast<Vector3D<float> &>(p->getVertices()[2]),
                                               fff)) {
                        doInter = true;

                        break;
                    }
            }
            size_t index = (i * screenDimension_.getX() + j) * 3;
            if (doInter) {
                screen_[index] = static_cast<unsigned char>(color.getX());
                screen_[index + 1] = static_cast<unsigned char>(color.getY());
                screen_[index + 2] = static_cast<unsigned char>(color.getZ());
            } else {
                screen_[index] = static_cast<unsigned char>(0);
                screen_[index + 1] = static_cast<unsigned char>(0);
                screen_[index + 2] = static_cast<unsigned char>(0);
            }

        }
    });
}

void Camera::computeImage(Scene scene) {

}

float Camera::getFieldOfViewRadian() {
    return fieldOfView_ * constants::PI / 180.f;
}
