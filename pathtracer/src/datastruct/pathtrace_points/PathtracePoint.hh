#pragma once

#include <Vector3D.hh>

class PathtracePoint {


public:

    PathtracePoint(const Vector3D<float> &position,
                   const Vector3D<float> &color,
                   const Vector3D<float> &normal);


    // Getter & Setters

    const Vector3D<float> &getPosition() const;

    void setPosition(const Vector3D<float> &position);

    const Vector3D<float> &getDiffuseColor() const;

    void setDiffuseColor(const Vector3D<float> &diffuse_color);

    const Vector3D<float> &getNormalOfTouchedElement() const;

    void setNormalOfTouchedElement(const Vector3D<float> &normal_of_touched_element);

protected:
    Vector3D<float> color_;
    Vector3D<float> normal_of_touched_element_;
    Vector3D<float> position_;
};
