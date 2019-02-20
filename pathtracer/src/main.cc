#include <iostream>
#include "parser/Parser.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif

int main() {
    std::cout << "test" << std::endl;
    Parser::fromPathToObjStruct(path_global);
    return 0;
}