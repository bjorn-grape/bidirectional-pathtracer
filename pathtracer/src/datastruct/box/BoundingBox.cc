#include "BoundingBox.hh"

BoundingBox::BoundingBox(const Vector3D<float> &mini, const Vector3D<float> &maxi) {
    readVector3DinMin(mini);
    readVector3DinMin(maxi);
}



bool BoundingBox::DoIntersect(Ray r) {
    float px = r.getPosition().getX();
    float ox = 1.f / r.getOrientation().getX();
    float py = r.getPosition().getY();
    float oy = 1.f / r.getOrientation().getY();

    float tmin;
    float tmax;
    float tymin;
    float tymax;
    if (ox >= 0) {
        tmin = (getMinX() - px) * ox;
        tmax = (getMaxX() - px) * ox;
    } else {
        tmax = (getMinX() - px) * ox;
        tmin = (getMaxX() - px) * ox;
    }

    if (oy >= 0) {
        tymin = (getMinY() - py) * oy;
        tymax = (getMaxY() - py) * oy;
    } else {
        tymax = (getMinY() - py) * oy;
        tymin = (getMaxY() - py) * oy;
    }


    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float pz = r.getPosition().getZ();
    float oz = r.getOrientation().getZ();

    float tzmin = (getMinZ() - pz) / oz;
    float tzmax = (getMaxZ() - pz) / oz;

    if (tzmin > tzmax)
        std::swap(tzmin, tzmax);

    return !((tmin > tzmax) || (tzmin > tmax));


}


BoundingBox::BoundingBox() = default;
