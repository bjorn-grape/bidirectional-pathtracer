#include "ObjectFileParser.hh"
#include "../scene_elements/Polygon.hh"
#include "../datastruct/scene/Scene.hh"
#include <iostream>

#define TINYOBJLOADER_IMPLEMENTATION

#include <tiny_obj_loader.h>


#ifdef  _WIN32
const std::string path_global = "..\\objs\\";
#else
const std::string relative_path = "../objs/";
#endif

void ObjectFileParser::fromPathToObjStruct(std::string path, Vector3D<float> position,
                                           std::vector<Polygon> &polygonVector, std::vector<Material> &mats) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, (relative_path + path).c_str());

    if (!ret)
        std::cerr << "error while parsing..." << std::endl;
    if (!err.empty()) { // `err` may contain warning message.
        std::cerr << err << std::endl;
    }

    for (auto &material : materials) {
        Material tmpma;
        tmpma.name = material.name;

        for (int j = 0; j < 3; ++j) {
            tmpma.ambient[j] = material.ambient[j];
            tmpma.diffuse[j] = material.diffuse[j];
            tmpma.specular[j] = material.specular[j];
            tmpma.transmittance[j] = material.transmittance[j];
            tmpma.emission[j] = material.emission[j];
        }
        tmpma.shininess = material.shininess;
        tmpma.ior = material.ior;
        tmpma.dissolve = material.dissolve;
        tmpma.ambient_texname = material.ambient_texname;
        tmpma.diffuse_texname = material.diffuse_texname;
        tmpma.specular_texname = material.specular_texname;
        tmpma.specular_highlight_texname = material.specular_highlight_texname;
        tmpma.bump_texname = material.bump_texname;
        tmpma.alpha_texname = material.alpha_texname;
        tmpma.reflection_texname = material.reflection_texname;
        mats.push_back(tmpma);
    }


    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            size_t fv = shapes[s].mesh.num_face_vertices[f];
            Polygon p;
            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
                // access to vertex

                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
                tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
                tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
                Vector3D<float> vertex(vx, vy, vz);
                tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
                tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
                tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];
                Vector3D<float> normal(nx, ny, nz);
                Vector2D<float> texcoord;
                if (2 * idx.texcoord_index < attrib.texcoords.size()) {
                    tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                    tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];
                    // Optional: vertex colors
                    texcoord = Vector2D<float>(tx, ty);
                }


                Vector3D<uint8_t> color;
                if (attrib.colors.size() >= 3u * idx.vertex_index + 2) {
                    tinyobj::real_t red = attrib.colors[3 * idx.vertex_index + 0];
                    tinyobj::real_t green = attrib.colors[3 * idx.vertex_index + 1];
                    tinyobj::real_t blue = attrib.colors[3 * idx.vertex_index + 2];
                    color = Vector3D<uint8_t>(static_cast<uint8_t>(red),
                                              static_cast<uint8_t>(green), static_cast<uint8_t>(blue));
                }
                p.add(vertex + position, normal, texcoord, color);

            }
            index_offset += fv;
            auto materialId = shapes[s].mesh.material_ids[f];

            p.setMaterial(mats.at(static_cast<unsigned long>(materialId)));
            polygonVector.emplace_back(p);
            // per-face material

        }
    }
}

void ObjectFileParser::fromAllObjsToObjStruct(const std::vector<ObjectPaths> &objectsPaths,
                                              Scene &scene) {
    std::vector<Polygon> allPoly;
    std::vector<Material> allMaterials;
    for (auto &objPath : objectsPaths) {
        std::vector<Polygon> tmp_poly_vector;
        std::vector<Material> tmp_materials;
        fromPathToObjStruct(objPath.getPath_obj(), objPath.getPosition(),
                            tmp_poly_vector, tmp_materials);
        allPoly.insert(allPoly.end(), tmp_poly_vector.begin(), tmp_poly_vector.end());
        allMaterials.insert(allMaterials.end(), tmp_materials.begin(), tmp_materials.end());
    }
    scene.kdtree = KDTree(allPoly);
    scene.AddMaterials(allMaterials);
}

