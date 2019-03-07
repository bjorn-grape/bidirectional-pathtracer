//
// Created by bjorn on 26/02/19.
//

#include <iostream>
#include <tiff.h>
#include "Camera.hh"
#include "tbb/tbb.h"

Camera::Camera(const float &screenDistance, const Vector2D<unsigned> &screenDimension,
               const Vector3D<float> &position, const Vector3D<float> &orientation,
               const float &fovDegree)
        : fieldOfView_(fovDegree)
          , screenDistance_(screenDistance)
          , screenDimension_(screenDimension)
          , position_(position)
          , orientation_(orientation) {
    fieldOfViewRadian = fieldOfView_ / 180.f * constants::PI;
}


void Camera::computeImage(std::vector<Polygon> polygons) {
    const float scaleDimension =
            static_cast<float>(screenDimension_.getY()) / static_cast<float>(screenDimension_.getX());
    float stepx;
    float stepy;
    if (scaleDimension > 1u) {
        stepx = fieldOfViewRadian / screenDimension_.getX();
        stepy = fieldOfViewRadian / screenDimension_.getY() * scaleDimension;
    } else {
        stepx = fieldOfViewRadian / screenDimension_.getX() / scaleDimension;
        stepy = fieldOfViewRadian / screenDimension_.getY();
    }

    auto screenCenterPoint = position_ + orientation_ * screenDistance_;
    screenCenterPoint -= (fieldOfViewRadian / 2.f);

    screen_.reserve(screenDimension_.getX() * screenDimension_.getY() * 3);
    tbb::parallel_for(size_t(0), static_cast<size_t>(screenDimension_.getY()), [&](size_t i) {
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {

            bool doInter = false;
            auto movingDir = screenCenterPoint + Vector3D(j * stepy, i * stepx, 0.f) - position_;
            Ray r = Ray(position_, movingDir);
            Vector3D<float> fff;
            for (const Polygon &p : polygons) {

                if (p.isTriangle())
                    if (r.intersectOneTriangle(const_cast<Vector3D<float> &>(p.getVertices()[0]),
                                               const_cast<Vector3D<float> &>(p.getVertices()[1]),
                                               const_cast<Vector3D<float> &>(p.getVertices()[2]),
                                               fff)) {
                        doInter = true;
                        break;
                    }
            }
            screen_[(i * screenDimension_.getX() + j) * 3] = static_cast<unsigned char>(doInter);
        }
    });
}


void Camera::dumpImageToPpm(std::string path) {
    std::ofstream ofstream(path);
    ofstream << "P2\n";
    ofstream << screenDimension_.getX() << " ";
    ofstream << screenDimension_.getY() << "\n";
    ofstream << "15\n";
    for (unsigned i = 0; i < screenDimension_.getY(); ++i) {
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {
            if ((screen_[(i * screenDimension_.getX() + j) * 3] != 0))
                ofstream << "15 ";
            else
                ofstream << "0 ";
        }
        ofstream << "\n";
    }
}

Camera &Camera::operator=(const Camera &camera) {
    this->orientation_ = camera.orientation_;
    this->position_ = camera.position_;
    this->fieldOfViewRadian = camera.fieldOfViewRadian;
    this->screenDistance_ = camera.screenDistance_;
    this->screenDimension_ = camera.screenDimension_;
    return *this;
}

void Camera::computeImage(KDTree tree) {
    const float scaleDimension =
            static_cast<float>(screenDimension_.getY()) / static_cast<float>(screenDimension_.getX());
    float stepx;
    float stepy;
    if (scaleDimension > 1u) {
        stepx = fieldOfViewRadian / screenDimension_.getX();
        stepy = fieldOfViewRadian / screenDimension_.getY() * scaleDimension;
    } else {
        stepx = fieldOfViewRadian / screenDimension_.getX() / scaleDimension;
        stepy = fieldOfViewRadian / screenDimension_.getY();
    }

    auto screenCenterPoint = position_ + orientation_ * screenDistance_;
    screenCenterPoint -= (fieldOfViewRadian / 2.f);
    screen_.reserve(screenDimension_.getX() * screenDimension_.getY() * 3);

    tbb::parallel_for(size_t(0), static_cast<size_t>(screenDimension_.getY()), [&](size_t i) {
        for (unsigned j = 0; j < screenDimension_.getX(); ++j) {

            bool doInter = false;
            auto movingDir = screenCenterPoint + Vector3D(j * stepy, i * stepx, 0.f) - position_;
            Ray r = Ray(position_, movingDir);
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
            screen_[(i * screenDimension_.getX() + j) * 3] = static_cast<unsigned char>(doInter);
        }
    });
}
