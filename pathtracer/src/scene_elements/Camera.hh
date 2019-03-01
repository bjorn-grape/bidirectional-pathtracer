#pragma once

#include <vector>
#include <fstream>

#include "fixed_size_vectors/Vector3D.hh"
#include "fixed_size_vectors/Vector2D.hh"
#include "Polygon.hh"
#include "Ray.hh"

class Camera {
public:
    Camera(float screenDistance, const Vector2D<int> &screenDimension,
           const Vector3D<float> &position, const Vector3D<float> &orientation);

    void computeImage(std::vector<Polygon> polygons);

    void dumpImageToPpm();

private:
    const float fieldOfView = 60.f;
    const float fieldOfViewRadian = fieldOfView / 180.f * constants::PI;
    float screenDistance_;
    Vector2D<int> screenDimension_;
    std::vector<uint8_t> screen_;
    Vector3D<float> position_;
    Vector3D<float> orientation_;
};


