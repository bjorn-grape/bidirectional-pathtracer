#include "PathtraceImageFactory.hh"

PathtraceImageFactory::PathtraceImageFactory(const Camera &cam, const Scene &scene)
        : ImageFactory(cam, scene) {}

void PathtraceImageFactory::computePixel(const Ray &ray, Vector3D<float> &cool) const {

}

void PathtraceImageFactory::compute() {


    travelScreen();
}
