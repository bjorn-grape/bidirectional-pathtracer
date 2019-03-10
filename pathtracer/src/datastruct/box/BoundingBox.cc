#include "BoundingBox.hh"

BoundingBox::BoundingBox(const Vector3D<float> &mini, const Vector3D<float> &maxi) {
    readVector3DinMin(mini);
    readVector3DinMax(maxi);
}


bool BoundingBox::DoIntersect(Ray r) {
    float px = r.getPosition().getX();
    float ox = 1.f / r.getDirection().getX();
    float py = r.getPosition().getY();
    float oy = 1.f / r.getDirection().getY();

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
    float oz = 1.f / r.getDirection().getZ();

    float tzmin = (getMinZ() - pz) * oz;
    float tzmax = (getMaxZ() - pz) * oz;

    if (tzmin > tzmax)
        std::swap(tzmin, tzmax);

    return !((tmin > tzmax) || (tzmin > tmax));


}

bool BoundingBox::FasterDoIntersect(Ray r) {
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    int signx = r.getSign()[0];
    float invdirx = r.getInvDirection().getX();
    float originx = r.getPosition().getX();

    int signy = r.getSign()[1];
    float invdiry = r.getInvDirection().getY();
    float originy = r.getPosition().getY();


    tmin = ((*this)[signx][0] - originx) * invdirx;
    tmax = ((*this)[1 - signx][0] - originx) * invdirx;
    tymin = ((*this)[signy][1] - originy) * invdiry;
    tymax = ((*this)[1 - signy][1] - originy) * invdiry;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    int signz = r.getSign()[2];
    float invdirz = r.getInvDirection().getZ();
    float originz = r.getPosition().getZ();

    tzmin = ((*this)[signz][2] - originz) * invdirz;
    tzmax = ((*this)[1 - signz][2] - originz) * invdirz;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;
//    if (tzmin > tmin)
//        tmin = tzmin;
//    if (tzmax < tmax)
//        tmax = tzmax;

    return true;
}


BoundingBox::BoundingBox() = default;

const Vector3D<float> BoundingBox::toleranceBoundaries = Vector3D(0.05f, 0.05f, 0.05f);