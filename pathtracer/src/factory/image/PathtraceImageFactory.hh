#pragma once

#include <serialized/camera/Camera.hh>
#include <pathtrace_points/LightPoint.hh>
#include "ImageFactory.hh"

class PathtraceImageFactory : public ImageFactory {
public:
    PathtraceImageFactory(const Camera &cam, const Scene &scene);
    virtual void computePixel(const Ray &ray, Vector3D<float> &cool)  const;
    void compute();

private:
    LightPoint lightPoint;
};


