#include "KDNode.hh"
#include "../../tools/Tools.hh"

void KDNode::build(vectorIterator it1, vectorIterator it2, const BoundingBox &box) {

    auto axis  = box.GetLargestDimension();
    Polygon::setComparisonfactor(axis);
    std::sort(it1,it2);

}
