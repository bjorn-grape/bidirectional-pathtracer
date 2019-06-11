#include <iostream>
#include "ObjectFileParser.hh"
#include "Executor.hh"
#include "CliParser.hh"
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>


int main(int argc, const char *argv[]) {

    CliParser cliParser(argc, argv);
    Executor executor;
    executor.load(cliParser.getPathSave());
    executor.setSavePath("mine.ppm");
    executor.setType(Executor::pathtrace);
    executor.run();

    return 0;
}
