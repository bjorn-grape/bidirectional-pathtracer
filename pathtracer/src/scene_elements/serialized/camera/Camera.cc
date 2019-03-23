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


void getPixelInfos(const Ray &ray, Scene &scene, Vector3D<float> &cool) {
    Polygon intersect_poly;
    bool hit = scene.kdtree.getIntersectionPoly(ray, intersect_poly);


    if (hit) {
        Vector3D<float> intersectionPoint;
        ray.intersect(intersect_poly, intersectionPoint);
        Vector3D<float> N = intersect_poly.getNormalAt(intersectionPoint);
//        for (int i = 0; i < 3; ++i) {
//            N += intersect_poly.getNormals()[i];
//        }
//        N /= 3;
        Vector3D<float> Ks = Vector3D(intersect_poly.getMaterial().specular);
        Vector3D<float> Kd = Vector3D(intersect_poly.getMaterial().diffuse);
        Vector3D<float> Ka = Vector3D(intersect_poly.getMaterial().ambient);
        float Alpha = 1;//intersect_poly.getMaterial().shininess;
        Vector3D<float> V = ray.getDirection() * -1;

        Vector3D<float> Ia = scene.allLights.ambient_lights_[0].getColor_();

        Vector3D<float> Ip = Ka * Ia;
//
        for (const auto &light: scene.allLights.directional_lights_) {
            Vector3D<float> Lm = light.getDirection() * -1;
            Vector3D<float> Rm = 2.f * (Lm.dotproduct(N)) * N - Lm;
            Vector3D<float> Id = light.getColor_();
            Ip += Kd * (Lm.dotproduct(N)) * Id /*+ (Ks * Rm.dotproduct(V)).power(Alpha) * 0.1f*/;
        }

        float R = std::max(0.f, std::min(Ip.getX(), 1.f));
        float G = std::max(0.f, std::min(Ip.getY(), 1.f));
        float B = std::max(0.f, std::min(Ip.getZ(), 1.f));
        cool = Vector3D<float>(R, G, B) * 255;
    } else
        cool = Colors::DARKGREY * 255;

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
            Vector3D<float> pixel;
            getPixelInfos(ray, scene, pixel);
            size_t index = (i * screenDimension_.getX() + j) * 3;
            screen_[index] = static_cast<unsigned char>(pixel.getX());
            screen_[index + 1] = static_cast<unsigned char>(pixel.getY());
            screen_[index + 2] = static_cast<unsigned char>(pixel.getZ());
        }
    });
//    }
}


float Camera::getFieldOfViewRadian() {
    return fieldOfView_ * constants::PI / 180.f;
}
