#pragma once

#include "mesh/types.hpp"

namespace core
{
    struct model // TODO can this go in common? should go inside common?
    {
        std::vector<mesh::model> geometries; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}