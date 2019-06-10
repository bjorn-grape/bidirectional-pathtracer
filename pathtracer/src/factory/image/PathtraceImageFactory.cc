#include "PathtraceImageFactory.hh"

PathtraceImageFactory::PathtraceImageFactory(const Camera &cam, const Scene &scene)
        : ImageFactory(cam, scene)
        , lightPoint(scene.kdtree){

}

void PathtraceImageFactory::computePixel(const Ray &ray, Vector3D<float> &cool) const {

}

void PathtraceImageFactory::compute() {
    if (scene_.allLights.directional_lights_.empty())
        return;

    DirectionalLight d1 = scene_.allLights.directional_lights_[0];

    lightPoint.setPosition(Vector3D<float>() - d1.getDirection());
    lightPoint.setDiffuseColor(d1.getColor_());
    lightPoint.setNormalOfTouchedElement(d1.getDirection());
    lightPoint.setDepth(3);
    lightPoint.setRayNumber(10);

    travelScreen();
}
