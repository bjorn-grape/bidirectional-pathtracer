#pragma once
#include "AllMaterialContainer.hh"

inline const Material &AllMaterialContainer::getMaterialAt(const unsigned &pos) {
    return materials_[pos];
}

inline const RGBImage &AllMaterialContainer::getImageNamed(const std::string &path) {
    return images_[path];
}

inline void AllMaterialContainer::addMaterials(const std::vector<Material> &maters) {
    materials_.insert(materials_.end(), maters.begin(), maters.end());

}

inline std::vector<Material> &AllMaterialContainer::getMaterials() {
    return materials_;
}
