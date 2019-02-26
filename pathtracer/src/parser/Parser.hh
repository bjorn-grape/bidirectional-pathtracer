//
// Created by bjorn on 19/02/19.
//

#ifndef PATHTRACER_PARSER_HH
#define PATHTRACER_PARSER_HH

#include<string>
#include "../scene_elements/Polygon.hh"


class Parser {

public :
    static std::vector<Polygon> fromPathToObjStruct(std::string path);
};


#endif //PATHTRACER_PARSER_HH
