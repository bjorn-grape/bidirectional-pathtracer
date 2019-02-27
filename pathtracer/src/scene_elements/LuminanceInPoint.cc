//
// Created by claus on 26/02/2019.
//

#include "LuminanceInPoint.hh"
#include "Ray.hh"

bool LuminanceInPoint::shadow_ray(Vector3D<float> p1, Vector3D<float> p2)
{
    Vector3D<float> direction = p1 - p2;
    for (auto it = objects_.begin(); it != objects_.end(); it++)
    {
        Ray shadow = Ray(p1, direction);

    }
}