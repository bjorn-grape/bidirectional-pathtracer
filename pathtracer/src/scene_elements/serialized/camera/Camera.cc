//
// Created by bjorn on 26/02/19.
//

#include <iostream>
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



Camera &Camera::operator=(const Camera &camera) {
    this->orientation_ = camera.orientation_;
    this->position_ = camera.position_;
    this->screenDimension_ = camera.screenDimension_;
    return *this;
}






float Camera::getFieldOfViewRadian() const{
    return fieldOfView_ * constants::PI / 180.f;
}

Camera::screenType Camera::getScreenType() const {
    return screen_type_;
}

void Camera::initPerspective(float &stepx, float &stepy, Vector3D<float> &screenUpLeftVector) const{
    const float scaleDimension =
            static_cast<float>(screenDimension_.getY()) / static_cast<float>(screenDimension_.getX());
    if (scaleDimension > 1u) {
        stepx = getFieldOfViewRadian() / screenDimension_.getX();
        stepy = getFieldOfViewRadian() / screenDimension_.getY() * scaleDimension;
    } else {
        stepx = getFieldOfViewRadian() / screenDimension_.getX() / scaleDimension;
        stepy = getFieldOfViewRadian() / screenDimension_.getY();
    }
    screenUpLeftVector = orientation_;
//    Vector3D<float> howToRotate = Vector3D<float>(-stepy * screenDimension_.getY() / 2.f,
//                                                  -stepx * screenDimension_.getX() / 2.f,
//                                                  0);
//    screenUpLeftVector.rotate(howToRotate);
}

size_t Camera::getScreenDimensionX() const {
    return screenDimension_.getX();
}

size_t Camera::getScreenDimensionY() const {
    return screenDimension_.getY();
}

Vector3D<float> Camera::getPosition() const {
    return position_;
}
