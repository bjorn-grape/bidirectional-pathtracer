#pragma once

#include <string>
#include "SceneSave.hh"

class Executor {

public:

    Executor();

    enum jobType {
        none,
        build_scene,
        render_scene,
        buildTreeAndPrint
    };

    void load(const std::string &path);

    void saveScene(const std::string &path);

    void setSavePath(const std::string& path);

    void setType(jobType type);

    void run();




private:
    void createTreeAndPrint();
    void renderSceneRaytracing();
    void renderScene();
    std::string save_path = "default.ppm";
    SceneSave sceneSave_;
    bool loaded_ = false;
    jobType type_ = none;
    std::unordered_map<jobType, void (*)(Executor &executor)> map_actions;
};


