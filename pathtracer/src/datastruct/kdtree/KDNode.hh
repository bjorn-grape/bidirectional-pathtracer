#pragma once

#include <memory>
#include <ostream>
#include "Vector3D.hh"
#include "Polygon.hh"
#include "BoundingBox.hh"
#include "SplitAxis.hh"
#include "Ray.hh"

class KDNode {
public:
    KDNode(std::vector<Polygon> &polygonsVect, const BoundingBox &box, const unsigned depth);

    void printInfix(unsigned depth, bool isleft);

    void getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList);

    void getIntersectionPolygon(const Ray &ray, Polygon &result, float &minDistance);

private:
    float splitValue_ = 0.f;
    SplitAxis::Axis splitAxis_ = SplitAxis::none;
    std::shared_ptr<BoundingBox> box_ = nullptr;
    std::shared_ptr<KDNode> left_ = nullptr;
    std::shared_ptr<KDNode> right_ = nullptr;
    std::shared_ptr<std::vector<Polygon>> polygons_;
};


