#pragma once

#include "SceneSave.hh"

class SceneFactory {
    SceneFactory() = delete;

public:
    static SceneSave BuildScene();
};


