#include "CliParser.hh"

CliParser::CliParser(int argc, const char **argv) {

    if(argc != 2){
        std::cerr << "Wrong argument number\n";
        exit(1);
    }
    std::string str(argv[1]);
    path_save_ = str;
}

std::string CliParser::getPathSave() const {
    return path_save_;
}
