#include <memory>

#include "KDTree.hh"
#include "../../tools/Tools.hh"

KDTree::KDTree( AllPolygonContainer &polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    BoundingBox b;
    auto indexList = polygons.getAllindexes();
    Tools<float>::extremumPolygonList(indexList, polygons, b);
    root_ = std::make_shared<KDNode>(indexList, polygons, b, 1);
}

void KDTree::printPrefix() {
    if (!root_) {
        std::cerr << "No Tree" << std::endl;
        return;
    }
    root_->printInfix(1, true);

}

void KDTree::getIntersectionList(const Ray &ray, std::unordered_set<unsigned> &resultList) {
    root_->getIntersectionList(ray, resultList);
    //Tools<float>::originVector = ray.getPosition();
    //Polygon::setComparisonfactor(Polygon::distanceToOrigin);
    //std::sort(resultList.begin(), resultList.end());
}
