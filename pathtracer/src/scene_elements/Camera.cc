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

    const float scaleDimension =
            static_cast<float>(screenDimension_.getY_()) / static_cast<float>(screenDimension_.getX_());
    auto upperleft = orientation_;
    auto thetas = Vector2D<float>();
    const float stepx = fieldOfViewRadian / screenDimension_.getX_();
    const float stepy = fieldOfViewRadian / screenDimension_.getY_() * scaleDimension;

    thetas -= fieldOfViewRadian;
    thetas /= 2.0f;
    thetas *= Vector2D<float>(1.f, 1.f * scaleDimension);

    upperleft.rotate(thetas);


    for (int i = 0; i < screenDimension_.getY_(); ++i) {
        auto left = upperleft;
        left.rotateOnX(stepy * i);


        for (int j = 0; j < screenDimension_.getX_(); ++j) {
            bool doInter = false;
            auto movingDir = left;
            movingDir.rotateOnY(stepx * j);
            Ray r = Ray(position_, movingDir);
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
    for (int i = 0; i < screenDimension_.getY_(); ++i) {
        for (int j = 0; j < screenDimension_.getX_(); ++j) {
            if ((screen_[(i * screenDimension_.getX_() + j) * 3] != 0))
                ofstream << "15 ";
            else
                ofstream << "0 ";
        }
        ofstream << "\n";
    }
}
