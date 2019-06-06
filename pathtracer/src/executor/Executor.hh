#pragma once

#include <string>
#include "SceneSave.hh"

class Executor {

public:

    Executor();

    enum jobType {
        none,
        buildscene,
        raytrace,
        pathtrace,
        buildTreeAndPrint
    };

    void load(const std::string &path);

    void save(const std::string &path);

    void setSavePath(const std::string& path);

    void setType(jobType type);

    void run();




private:
    void createTreeAndPrint();
    void renderSceneRaytracing();
    void renderScenePathtracing();
    std::string save_path = "default.ppm";
    SceneSave sceneSave_;
    bool loaded_ = false;
    jobType type_ = none;
    std::unordered_map<jobType, void (*)(Executor &executor)> map_actions;
};


