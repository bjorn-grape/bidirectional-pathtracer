//
// Created by bjorn on 02/03/19.
//

#ifndef PATHTRACER_SCENEFACTORY_HH
#define PATHTRACER_SCENEFACTORY_HH


#include "../scene_elements/serialized/SceneSave.hh"

class SceneFactory {
public:
    static SceneSave BuildScene();
};


#endif //PATHTRACER_SCENEFACTORY_HH
