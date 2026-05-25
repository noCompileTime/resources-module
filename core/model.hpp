#pragma once

#include "geometry/geometry_type.hpp"

namespace core
{
    struct model // TODO can this go in common? should go inside common?
    {
        std::vector<geometry::model> geometries; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}