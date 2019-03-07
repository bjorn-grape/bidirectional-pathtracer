#pragma once

#include <memory>
#include <ostream>
#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../../scene_elements/Polygon.hh"
#include "../box/BoundingBox.hh"
#include "../SplitAxis.hh"
#include "../../scene_elements/Ray.hh"

class KDNode {
public:
    KDNode(std::vector<Polygon> &polygonsVect, const BoundingBox &box);
    void printInfix(unsigned depth, bool isleft);
    void getIntersectionList(const Ray& ray, std::vector<Polygon*>& resultList);

private:
    float splitValue_ = 0.f;
    SplitAxis::Axis splitAxis_ = SplitAxis::none;
    std::shared_ptr<BoundingBox> box_ = nullptr;
    std::shared_ptr<KDNode> left_ = nullptr;
    std::shared_ptr<KDNode> right_ = nullptr;
    std::shared_ptr<std::vector<Polygon>> polygons_;
};


