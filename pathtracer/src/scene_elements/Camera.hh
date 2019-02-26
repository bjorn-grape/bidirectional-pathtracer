//
// Created by bjorn on 26/02/19.
//

#ifndef PATHTRACER_CAMERA_HH
#define PATHTRACER_CAMERA_HH


#include <vector>
#include "fixed_size_vectors/Vector3D.hh"
#include "fixed_size_vectors/Vector2D.hh"
#include "Polygon.hh"

class Camera {

public:
    Camera(float screenDistance, const Vector2D<int> &screenDimension_,
           const Vector3D<float> &position_, const Vector3D<float> &orientation_);

    void computeImage(std::vector<Polygon> polygons);
    void dumpImageToPpm();
private:
    float screenDistance;
    Vector2D<int> screenDimension_;
    std::vector<uint8_t> screen_;
    Vector3D<float> position_;
    Vector3D<float> orientation_;
};


#endif //PATHTRACER_CAMERA_HH
