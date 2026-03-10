#pragma once

#include "obj_object.hpp"

namespace models
{
    struct obj_data
    {
        std::vector<math::vec3> positions;
        std::vector<math::vec2> texcoords;
        std::vector<math::vec3> normals;

        std::vector<obj_object> objects;
    };
}