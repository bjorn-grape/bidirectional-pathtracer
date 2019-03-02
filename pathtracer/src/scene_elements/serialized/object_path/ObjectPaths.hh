#pragma once

#include <string>
#include <cereal/access.hpp>
#include <cereal/cereal.hpp>
#include "../../fixed_size_vectors/Vector3D.hh"


class ObjectPaths {
public:
    ObjectPaths() = default;

    ObjectPaths(const std::string &path_mtl_, const std::string &path_obj_, const Vector3D<float> &position_);

    void setPath_mtl(const std::string &path_mtl_);

    void setPath_obj(const std::string &path_obj_);

    void setPosition(const Vector3D<float> &position_);


    const std::string &getPath_obj() const;

    const std::string &getPath_mtl() const;

    const Vector3D<float> &getPosition() const;

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(path_obj_), CEREAL_NVP(path_mtl_), CEREAL_NVP(position_));
    }

private:
    std::string path_mtl_;
    std::string path_obj_;
    Vector3D<float> position_;
};
