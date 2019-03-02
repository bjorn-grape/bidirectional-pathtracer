#include "ObjectPaths.hh"

const std::string &ObjectPaths::getPath_obj() const {
    return path_obj_;
}

const std::string &ObjectPaths::getPath_mtl() const {
    return path_mtl_;
}

const Vector3D<float> &ObjectPaths::getPosition() const {
    return position_;
}

ObjectPaths::ObjectPaths(const std::string &path_mtl_,
                         const std::string &path_obj_,
                         const Vector3D<float> &position_)
        : path_mtl_(path_mtl_)
          , path_obj_(path_obj_)
          , position_(position_) {}

void ObjectPaths::setPath_mtl(const std::string &path_mtl_) {
    ObjectPaths::path_mtl_ = path_mtl_;
}

void ObjectPaths::setPath_obj(const std::string &path_obj_) {
    ObjectPaths::path_obj_ = path_obj_;
}

void ObjectPaths::setPosition(const Vector3D<float> &position_) {
    ObjectPaths::position_ = position_;
}
