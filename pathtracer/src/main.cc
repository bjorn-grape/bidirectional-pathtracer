#include <iostream>
#include "parser/ObjectFileParser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"
#include "scene_elements/fixed_size_vectors/Vector3D.hh"
#include "scene_elements/Ray.hh"
#include "scene_elements/serialized/camera/Camera.hh"
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "scene_elements/serialized/object_path/ObjectPaths.hh"
#include "executor/Executor.hh"
#include "parser/CliParser.hh"

int main(int argc,const char *argv[]) {

    CliParser cliParser(argc, argv);
    Executor executor;
    executor.setType(Executor::buildscene);
    executor.run();
    executor.save(cliParser.getPathSave());

    return 0;
}
