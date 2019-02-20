#ifndef PATHTRACER_POINT_LIGHT_HH
#define PATHTRACER_POINT_LIGHT_HH


#include "Light.hh"

class PointLight : public Light {
    Vector3D<float> position;
public:
    PointLight(const Vector3D<float> &position, float radius);

public:
    const Vector3D<float> &getPosition() const;

    void setPosition(const Vector3D<float> &position);

    PointLight(float intensity, const Vector3D<uint8_t> &color,
            const Vector3D<float> &position, float radius);

    float getRadius() const;

    void setRadius(float radius);

private:
    float radius;
};


#endif //PATHTRACER_POINT_LIGHT_HH
