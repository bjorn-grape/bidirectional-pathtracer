#pragma once

#include "ImageFactory.hh"

class PhongImageFactory : public ImageFactory{


public:
    PhongImageFactory(const Camera &cam, const Scene &scene);
    virtual void computePixel(const Ray &ray, Vector3D<float> &cool)  const;
    void compute();
};


