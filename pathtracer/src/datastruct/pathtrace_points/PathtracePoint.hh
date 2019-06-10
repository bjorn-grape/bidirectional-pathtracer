#pragma once

#include <Vector3D.hh>
#include <kdtree/KDTree.hh>

class PathtracePoint {


public:

    PathtracePoint(Vector3D<float> &position,
                   Vector3D<float> &color,
                   Vector3D<float> &normal,
                   size_t depth_,
                   size_t point_number_,
                   KDTree &kd_tree);

    PathtracePoint(const Vector3D<float> &position,
                   const Vector3D<float> &color,
                   const Vector3D<float> &normal,
                   const size_t depth_,
                   const size_t point_number_,
                   const KDTree &kd_tree);


    // Getter & Setters


    const Vector3D<float> &getPosition() const;

    void setPosition(const Vector3D<float> &position);

    const Vector3D<float> &getDiffuseColor() const;

    void setDiffuseColor(const Vector3D<float> &diffuse_color);

    const Vector3D<float> &getNormalOfTouchedElement() const;

    void setNormalOfTouchedElement(const Vector3D<float> &normal_of_touched_element);

    virtual void addToChildren(Vector3D<float> &position,
                               Vector3D<float> &color,
                               Vector3D<float> &normal,
                               size_t depth_,
                               size_t point_number_,
                               const KDTree &kd_tree) = 0;

protected:
    void setup();

    Vector3D<float> position_;
    Vector3D<float> color_;

    Vector3D<float> normal_of_touched_element_;

    size_t depth_;
    size_t point_number_;
    const KDTree &kdTree_;
};
