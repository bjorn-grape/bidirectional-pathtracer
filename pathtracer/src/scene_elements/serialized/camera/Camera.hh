#pragma once

#include <vector>
#include <fstream>

#include "../../fixed_size_vectors/Vector3D.hh"
#include "../../fixed_size_vectors/Vector2D.hh"
#include "../../Polygon.hh"
#include "../../Ray.hh"
#include "../../../datastruct/kdtree/KDTree.hh"
#include "../../../datastruct/scene/Scene.hh"

class Camera {
public:

    Camera() = default;

    Camera &operator=(const Camera &);


    Camera(const float &screenDistance, const Vector2D<unsigned> &screenDimension,
           const Vector3D<float> &position, const Vector3D<float> &orientation,
           const float &fovDegree);

    void computeImageRaw(KDTree tree);
    void computeImage(Scene scene);

    void dumpImageToPpm(std::string path);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(fieldOfView_), CEREAL_NVP(fieldOfViewRadian),
           CEREAL_NVP(screenDistance_), CEREAL_NVP(screenDimension_),
           CEREAL_NVP(screen_), CEREAL_NVP(position_),
           CEREAL_NVP(orientation_));
    }


private:
    float fieldOfView_ = 0.f;
    float fieldOfViewRadian = 0.f;
    float screenDistance_= 0.f;
    Vector2D<unsigned> screenDimension_;
    std::vector<uint8_t> screen_;
    Vector3D<float> position_;
    Vector3D<float> orientation_;
};


