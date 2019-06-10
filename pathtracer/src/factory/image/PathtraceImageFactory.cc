#include "PathtraceImageFactory.hh"

PathtraceImageFactory::PathtraceImageFactory(const Camera &cam, const Scene &scene)
        : ImageFactory(cam, scene)
          , lightPoint(scene.kdtree) {

}

void PathtraceImageFactory::computePixel(const Ray &ray, Vector3D<float> &cool) const {
//    std::cout << "computing pixel" << std::endl;
    CameraPoint camPT = CameraPoint(ray.getPosition(), cool, ray.getDirection(), 1, 1, scene_.kdtree);
    camPT.gatherLightsSeen(lightPoint, cool);
    float R = std::min(std::max(cool.getX(), 0.f), 1.f);
    float G = std::min(std::max(cool.getY(), 0.f), 1.f);
    float B = std::min(std::max(cool.getZ(), 0.f), 1.f);
    cool = Vector3D(R,G,B);
}

void PathtraceImageFactory::compute() {
    if (scene_.allLights.directional_lights_.empty())
        return;

    DirectionalLight d1 = scene_.allLights.directional_lights_[0];

    lightPoint.setPosition(Vector3D<float>() - d1.getDirection() * 5.f);
    lightPoint.setDiffuseColor(d1.getColor_());
    lightPoint.setNormalOfTouchedElement(d1.getDirection());
    lightPoint.setDepth(1);
    lightPoint.setRayNumber(1);
    lightPoint.setup();
    travelScreen();
}
