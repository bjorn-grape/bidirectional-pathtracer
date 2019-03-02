
#include "gtest/gtest.h"
#include "object_path/ObjectPaths.hh"
#include "Vector3D.hh"
#include <vector>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

TEST(TestSerialize, testVectorClass) {

    ObjectPaths o1 = ObjectPaths("o1", "oo1", Vector3D<float>(2, 2, 2));
    ObjectPaths o2 = ObjectPaths("o2", "oo2", Vector3D<float>(1, 1, 1));
    std::vector<ObjectPaths> vec;
    vec.emplace_back(o1);
    vec.emplace_back(o2);

    std::stringstream out;
    cereal::JSONOutputArchive dumpToJson(out);
    dumpToJson(CEREAL_NVP(vec));

    std::string strToLoad = out.str() + "\n}";

    std::stringstream in(strToLoad);
    cereal::JSONInputArchive loadToJson(in);

    std::vector<ObjectPaths> vecout;
    loadToJson(vecout);
    ASSERT_EQ("oo1",vecout[0].getPath_obj());

}