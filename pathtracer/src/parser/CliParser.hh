#pragma once

#include <cereal/types/string.hpp>

class CliParser {
public:
    CliParser(int argc, const char* argv[]);

    std::string getPathSave() const;

private:
    std::string path_save_;
};


