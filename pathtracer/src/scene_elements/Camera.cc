//
// Created by bjorn on 26/02/19.
//

#include <fstream>
#include "Camera.hh"
#include "Polygon.hh"
#include "Ray.hh"

Camera::Camera(float screenDistance, const Vector2D<int> &screenDimension_,
               const Vector3D<float> &position_,
               const Vector3D<float> &orientation_)
        : screenDistance(screenDistance)
          , screenDimension_(screenDimension_)
          , position_(position_)
          , orientation_(orientation_) {}

void Camera::computeImage(std::vector<Polygon> polygons) {
    Vector3D<float> screenCenter = position_ + orientation_ * screenDistance;
    const float step = 10.f;
    screenCenter -= Vector3D(step * screenDimension_.getX_() / 2.f,
                             step * screenDimension_.getY_() / 2.f,
                             0.f);
    for (int i = 0; i < screenDimension_.getX_(); ++i) {
        for (int j = 0; j < screenDimension_.getY_(); ++j) {
            bool doInter = false;
            Ray r = Ray(position_, screenCenter + Vector3D(i * step, j * step, 0.0f));
            Vector3D<float> fff;
            for (const Polygon &p : polygons) {

                if (p.isTriangle())
                    if (r.doIntersect(const_cast<Vector3D<float> &>(p.getVectices_()[0]),
                                      const_cast<Vector3D<float> &>(p.getVectices_()[1]),
                                      const_cast<Vector3D<float> &>(p.getVectices_()[2]),
                                      fff)) {
                        doInter = true;
                        break;
                    }
            }

            if (doInter)
                screen_.emplace_back(1);
            else
                screen_.emplace_back(0);
            screen_.emplace_back(0);
            screen_.emplace_back(0);
        }
    }
}

void Camera::dumpImageToPpm() {
    std::ofstream ofstream("plop.ppm");
    ofstream << "P2\n";
    ofstream << screenDimension_.getX_() << " ";
    ofstream << screenDimension_.getY_() << "\n";
    ofstream << "15\n";
    for (int i = 0; i < screenDimension_.getX_(); ++i) {
        for (int j = 0; j < screenDimension_.getY_(); ++j) {
            if ((screen_[(i * screenDimension_.getX_() + j) * 3] != 0))
                ofstream << "15 ";
            else
                ofstream << "0 ";
        }
        ofstream << "\n";
    }
}
