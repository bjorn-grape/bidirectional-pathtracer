#include <iostream>
#include "parser/Parser.hh"

int main() {
    std::cout << "test" << std::endl;
    Parser::fromPathToObjStruct("../objs/cube.obj");
    return 0;
}