#pragma once

#include "geometry/types.hpp"

namespace core
{
    struct model
    {
        std::vector<geometry::model> geometries; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}