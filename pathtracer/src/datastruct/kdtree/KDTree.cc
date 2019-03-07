#include <memory>

#include "KDTree.hh"
#include "../../tools/Tools.hh"

KDTree::KDTree(std::vector<Polygon> &polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    BoundingBox b;
    Tools<float>::extremumPolygonList(polygons, b);
    root_ = std::make_shared<KDNode>(polygons, b);
}

void KDTree::printPrefix() {
    if (!root_) {
        std::cerr << "No Tree" << std::endl;
        return;
    }
    root_->printInfix(1, true);

}
