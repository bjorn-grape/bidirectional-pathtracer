#pragma once

#include <string>

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif


#include "../scene_elements/serialized/SceneSave.hh"

class Executor {

public:

    Executor();

    enum jobType {
        none,
        binaryTest,
        buildscene,
        binaryTest2
    };

    void load(const std::string &path);

    void save(const std::string &path);

    void localBuildScene();

    void setType(jobType type);

    void run();


private:
    SceneSave sceneSave_;
    bool loaded_ = false;
    jobType type_ = none;
    std::unordered_map<jobType, void (*)(Executor &executor)> map_actions;
};


