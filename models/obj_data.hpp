#pragma once

#include "obj_object.hpp"

#include "vec2.hpp"
#include "vec3.hpp"

namespace models
{
    struct obj_data
    {
        std::vector<math::vec3> positions;
        std::vector<math::vec3> normals;
        std::vector<math::vec2> texcoords;

        std::vector<obj_object> objects;
    };
}