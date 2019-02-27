//
// Created by bjorn on 24/02/19.
//

#pragma once

#include "fixed_size_vectors/Vector3D.hh"
#include "Polygon.hh"
#include <exception>
#include <vector>

class Ray {

public:
    Ray(const Vector3D<float> &position, const Vector3D<float> &direction);

    bool intersectOneTriangle(const Vector3D<float>& v0, const Vector3D<float>& v1,
                     const Vector3D<float>& v2, Vector3D<float>& intersection) const;

    bool intersectOnePolygon(std::vector<Vector3D<float>> vertices, Vector3D<float>& intersection) const;

    std::vector<Vector3D<float>> intersectAllObjects(const std::vector<Polygon>& objects);

    const Vector3D<float> &getPosition_() const;
    void setPosition_(const Vector3D<float> &position);
    const Vector3D<float> &getOrientation() const;
    void setOrientation(const Vector3D<float> &orientation);

private:
    Vector3D<float> direction_;
    Vector3D<float> position_;
};
