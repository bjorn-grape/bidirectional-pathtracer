#ifndef PATHTRACER_SPOTLIGHT_HH
#define PATHTRACER_SPOTLIGHT_HH


#include "Light.hh"

class SpotLight : public Light {
public:
    float angle;

    float getAngle() const;

    void setAngle(float angle);

    const Vector3D<float> &getDirection() const;

    void setDirection(const Vector3D<float> &direction);

    const Vector3D<float> &getPosition() const;

    void setPosition(const Vector3D<float> &position);

    Vector3D<float> direction;
    Vector3D<float> position;

};


#endif //PATHTRACER_SPOTLIGHT_HH
