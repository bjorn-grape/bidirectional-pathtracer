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

    enum screenType{
        perspective,
        orthographic
    };

    Camera() = default;

    Camera &operator=(const Camera &);


    Camera(const Vector2D<unsigned> &screenDimension,
           const Vector3D<float> &position, const Vector3D<float> &orientation,
           const float &fovDegree);

    float getFieldOfViewRadian() const;

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(fieldOfView_), CEREAL_NVP(screenDimension_),
           CEREAL_NVP(screen_), CEREAL_NVP(position_),
           CEREAL_NVP(orientation_));
    }

    screenType getScreenType() const;

    void initPerspective(float& stepx,float& stepy,Vector3D<float>& perpective) const;

    size_t getScreenDimensionX() const;
    size_t getScreenDimensionY() const;
    Vector3D<float> getPosition() const;

private:
    float fieldOfView_ = 0.f;
    Vector2D<unsigned> screenDimension_;
    std::vector<uint8_t> screen_;
    Vector3D<float> position_;
    Vector3D<float> orientation_;
    // orthographic might be added later
    const screenType screen_type_ = perspective;
};


