#pragma once

#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../SplitAxis.hh"
#include "../../scene_elements/Ray.hh"

class BoundingBox {
public:
    BoundingBox(const Vector3D<float> &mini, const Vector3D<float> &maxi);

    BoundingBox();

    inline SplitAxis::Axis GetLargestDimension() const;
    inline SplitAxis::Axis GetSmallestDimension() const;

    inline Vector3D<float> GetDimensions() const;

    bool DoIntersect(Ray r);

    inline void readVector3DinMin(const Vector3D<float> &vector3D);

    inline void readVector3DinMax(const Vector3D<float> &vector3D);

    inline float getMinX() const;

    inline float getMinY() const;

    inline float getMinZ() const;

    inline float getMaxX() const;

    inline float getMaxY() const;

    inline float getMaxZ() const;

    inline void setExtremumFromPolygonList(const std::vector<Polygon> &polygons);

private:
    float min[3] = {0.f, 0.f, 0.f};
    float max[3] = {0.f, 0.f, 0.f};
};

#include "BoundingBox.hxx"