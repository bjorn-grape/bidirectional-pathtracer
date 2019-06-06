#pragma once

#include <vector>
#include <fstream>

#include "Vector3D.hh"
#include "Vector2D.hh"
#include "Polygon.hh"
#include "Ray.hh"
#include "KDTree.hh"
#include "Scene.hh"

class Camera {
public:

    Camera() = default;

    Camera &operator=(const Camera &);


    Camera(const Vector2D<unsigned> &screenDimension,
           const Vector3D<float> &position, const Vector3D<float> &orientation,
           const float &fovDegree);

    void travelScreen(Scene scene);

    void dumpImageToPpm(std::string path);

    float getFieldOfViewRadian();

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(fieldOfView_), CEREAL_NVP(screenDimension_),
           CEREAL_NVP(screen_), CEREAL_NVP(position_),
           CEREAL_NVP(orientation_));
    }


private:
    float fieldOfView_ = 0.f;
    Vector2D<unsigned> screenDimension_;
    std::vector<uint8_t> screen_;
    Vector3D<float> position_;
    Vector3D<float> orientation_;
};


