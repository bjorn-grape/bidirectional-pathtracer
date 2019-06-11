#include "PathtraceImageFactory.hh"

PathtraceImageFactory::PathtraceImageFactory(const Camera &cam, const Scene &scene)
        : ImageFactory(cam, scene) {
    size_t depth = 3;
    size_t rayNb = 10;
    for (auto dirLi :scene_.allLights.directional_lights_) {
        LightPoint lp = LightPoint(Vector3D<float>() - dirLi.getDirection() * 5.f,
                                   dirLi.getColor_(), dirLi.getDirection(),
                                   depth, rayNb, scene.kdtree);
        lp.setup();
        lightPoints.emplace_back(lp);
    }
}

void PathtraceImageFactory::computePixel(const Ray &ray, Vector3D<float> &cool) const {
//    std::cout << "computing pixel" << std::endl;
    CameraPoint camPT = CameraPoint(ray.getPosition(), cool, ray.getDirection(), 1, 10, scene_.kdtree);

    Vector3D<float> lightSum;
    for (const LightPoint &lp : lightPoints) {
        Vector3D<float> tempLight;
        camPT.gatherLightsSeen(lp, tempLight);
        lightSum += tempLight;
    }

    cool = lightSum / lightPoints.size();
    float R = std::min(std::max(cool.getX(), 0.f), 1.f);
    float G = std::min(std::max(cool.getY(), 0.f), 1.f);
    float B = std::min(std::max(cool.getZ(), 0.f), 1.f);
    cool = Vector3D(R, G, B);
}

void PathtraceImageFactory::compute() {
    if (scene_.allLights.directional_lights_.empty())
    {
    std::cout << "no light";
        return;
    }


    travelScreen();
}
