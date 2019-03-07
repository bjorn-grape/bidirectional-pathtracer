//
// Created by bjorn on 07/03/19.
//

#include <numeric>
#include <algorithm>
#include <iostream>
#include "PerformancesHolder.hh"

void PerformancesHolder::addTime(double t) {
    mtx.lock();
    times.push_back(t);
    mtx.unlock();
}

void PerformancesHolder::printInfos() {
    if (times.empty()) {
        std::cout << "counter empty\n";
        return;
    }
    std::sort(times.begin(), times.end());

    double median = times[times.size() / 2];
    double mean = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
    std::cout << "Results for " << name << "\n";
    std::cout << "Median : " << median << "s\n";
    std::cout << "Mean : " << mean << "s\n";
    std::cout << "Calls : " << times.size() << std::endl;

}

PerformancesHolder::PerformancesHolder(std::string n) {
    name = n;
}
