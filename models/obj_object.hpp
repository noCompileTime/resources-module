#pragma once

#include "obj_indices.hpp"

namespace models
{
    struct obj_object
    {
        std::string              name;
        std::vector<obj_indices> indices;
    };
}