//
// Created by bjorn on 26/02/19.
//

#include <iostream>
#include "Camera.hh"


Camera::Camera(float screenDistance, const Vector2D<int> &screenDimension,
               const Vector3D<float> &position,
               const Vector3D<float> &orientation)
        : screenDistance_(screenDistance)
          , screenDimension_(screenDimension)
          , position_(position)
          , orientation_(orientation) {}


void Camera::computeImage(std::vector<Polygon> polygons) {
    const float scaleDimension =
            static_cast<float>(screenDimension_.getY()) / static_cast<float>(screenDimension_.getX());
    auto upperleft = orientation_;
    auto thetas = Vector3D<float>();
    const float stepx = fieldOfViewRadian / screenDimension_.getX();
    const float stepy = fieldOfViewRadian / screenDimension_.getY()* scaleDimension ;

    thetas -= fieldOfViewRadian;
    thetas /= 2.0f;
    thetas *= Vector3D<float>(1.f, 1.f , 1.f * scaleDimension);

    upperleft.rotate(thetas);


    for (int i = 0; i < screenDimension_.getY(); ++i) {
        auto left = upperleft;
        left.rotateOnZ(stepy * i);


        for (int j = 0; j < screenDimension_.getX(); ++j) {
            bool doInter = false;
            auto movingDir = left;
            movingDir.rotateOnY(stepx * j);
            Ray r = Ray(position_, movingDir);
            //std::cout << "for couple ("<< i<< ","<< j<<") v = "<< movingDir << "\n";
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
    ofstream << screenDimension_.getX() << " ";
    ofstream << screenDimension_.getY() << "\n";
    ofstream << "15\n";
    for (int i = 0; i < screenDimension_.getY(); ++i) {
        for (int j = 0; j < screenDimension_.getX(); ++j) {
            if ((screen_[(i * screenDimension_.getX() + j) * 3] != 0))
                ofstream << "15 ";
            else
                ofstream << "0 ";
        }
        ofstream << "\n";
    }
}
