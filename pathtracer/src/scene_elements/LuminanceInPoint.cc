//
// Created by claus on 26/02/2019.
//

#include "LuminanceInPoint.hh"

bool LuminanceInPoint::IsShadowRay(Vector3D<float> p1, Vector3D<float> p2)
{
    Vector3D<float> direction = p2 - p1;
    Ray ray = Ray(p1, direction);

    std::vector<Vector3D<float>> intersections = ray.intersectAllObjects(objects_);
    //Compute distance(p1, intersection) < distance(p1, p2) ==> False there is no shadow_ray between p1 and p2
    for (const auto &intersection : intersections)
    {
        auto distance_p1_intersection = (intersection - p1).norm();
        auto distance_p1_p2 = direction.norm();
        if (distance_p1_intersection < distance_p1_p2)
            return false;
    }
    return true;
}


std::vector<Vector3D<float>> LuminanceInPoint::allShadowRays(Vector3D<float> p)
{
    std::vector<Vector3D<float>> shadow_ray;
    for (const auto &intersectPointLight : ray_light_)
    {
        if (this->IsShadowRay(p, intersectPointLight))
            shadow_ray.push_back(intersectPointLight);
    }
    return shadow_ray;
}


void LuminanceInPoint::luminanceOnePoint(Vector3D<float> p)
{
    std::vector<Vector3D<float>> shadow_ray = this->allShadowRays(p);
    //Compute Luminance of p
    /*FIXME*/
}


void LuminanceInPoint::luminanceAllPoint()
{
    for (auto it = ray_viewer_.rbegin(); it != ray_viewer_.rend(); it++)
    {
        this->luminanceOnePoint(*it);
        /*FIXME*/
    }
}
