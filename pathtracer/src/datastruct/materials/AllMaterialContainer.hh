#pragma once
#include <vector>
#include <unordered_map>
#include "RGBImage.hh"
#include "Material.hh"

class AllMaterialContainer {
public:
    void addImage(const std::string &path);
    inline void addMaterials(const std::vector<Material>& maters);
    inline std::vector<Material>& getMaterials();
    inline const Material & getMaterialAt(const unsigned &pos);
    inline const RGBImage &getImageNamed(const std::string &path);
private:
    std::vector<Material> materials_;
    std::unordered_map<std::string, RGBImage> images_;
};

#include "AllMaterialContainer.hxx"
