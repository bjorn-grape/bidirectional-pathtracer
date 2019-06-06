#include <memory>

#include "KDTree.hh"
#include "../../tools/Tools.hh"

KDTree::KDTree(std::vector<Polygon> &polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    BoundingBox b;
    b.setExtremumFromPolygonList(polygons);
    root_ = std::make_shared<KDNode>(polygons, b, 0);
}

void KDTree::printPrefix() {
    if (!root_) {
        std::cerr << "No Tree" << std::endl;
        return;
    }
    root_->printInfix(1, true);

}

void KDTree::getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList) {
    root_->getIntersectionList(ray, resultList);
}

bool KDTree::getIntersectionPoly(const Ray &ray, Polygon &result) const  {
    float dist = INFINITY;
    root_->getIntersectionPolygon(ray, result, dist);
    return dist != INFINITY;
}
