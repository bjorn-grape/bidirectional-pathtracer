#pragma once

#include<string>
#include "../scene_elements/Polygon.hh"


class Parser {

public :
    static std::vector<Polygon> fromPathToObjStruct(std::string path);
};


