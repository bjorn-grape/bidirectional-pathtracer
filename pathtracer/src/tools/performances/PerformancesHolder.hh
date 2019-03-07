#pragma once

#include <mutex>
#include <vector>

struct PerformancesHolder {

    PerformancesHolder(std::string n);
    std::mutex mtx;

    void addTime(double t);

    void printInfos();

    std::vector<double> times;
    std::string name;



};

