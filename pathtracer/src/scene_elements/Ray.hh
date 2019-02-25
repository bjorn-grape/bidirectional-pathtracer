//
// Created by bjorn on 24/02/19.
//

#ifndef PATHTRACER_RAYS_HH
#define PATHTRACER_RAYS_HH


#include "fixed_size_vectors/Vector3D.hh"

class Ray {

public:
    Ray(const Vector3D<float> &position_, const Vector3D<float> &orientation);

public:
    bool doIntersect(Vector3D<float> v0, Vector3D<float> v1, Vector3D<float> v2) const;

private:
    Vector3D<float> position_;
public:
    const Vector3D<float> &getPosition_() const;

    void setPosition_(const Vector3D<float> &position);

    const Vector3D<float> &getOrientation() const;

    void setOrientation(const Vector3D<float> &orientation);

private:
    Vector3D<float> direction_;
};


#endif //PATHTRACER_RAYS_HH
