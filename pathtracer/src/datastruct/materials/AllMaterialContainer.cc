#include "AllMaterialContainer.hh"

void AllMaterialContainer::addImage(const std::string &path) {
    auto img = RGBImage(path);
    images_[path] = img;
}


