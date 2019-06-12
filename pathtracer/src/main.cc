#include <iostream>
#include "ObjectFileParser.hh"
#include "Executor.hh"
#include "CliParser.hh"
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <chrono>

int main(int argc, const char *argv[]) {

    CliParser cliParser(argc, argv);
    Executor executor;
    executor.load(cliParser.getPathSave());
    executor.setSavePath("mine.ppm");
    executor.setType(Executor::pathtrace);
    auto start = std::chrono::system_clock::now();
    executor.run();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
