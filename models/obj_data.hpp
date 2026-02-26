#pragma once

namespace models
{
    struct obj_data
    {
        std::string object_name;

        std::vector<math::vec3> positions;
        std::vector<math::vec2> texcoords;
        std::vector<math::vec3> normals;

        std::vector<std::tuple< uint32_t, uint32_t, uint32_t>> indices;
    };
}