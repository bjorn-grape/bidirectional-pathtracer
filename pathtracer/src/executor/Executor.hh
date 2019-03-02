#pragma once

#include <string>

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif


#include "../scene_elements/serialized/SceneSave.hh"

class Executor {



    enum jobType {
        none,
        binaryTest
    };

    void load(std::string &path);

    void save(std::string &path);

    void setType(jobType type);


private:
    SceneSave sceneSave_;
    bool loaded_ = false;
    jobType type_ = none;

};


