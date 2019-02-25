//
// Created by bjorn on 19/02/19.
//
#define TINYOBJLOADER_IMPLEMENTATION

#include "Parser.hh"
#include <tiny_obj_loader.h>
#include <iostream>

std::vector<Triangle> Parser::fromPathToObjStruct(std::string path) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str());

    if (!err.empty()) { // `err` may contain warning message.
        std::cerr << err << std::endl;
    }
}
