#pragma once

#include "core/vertex/geometry.hpp"

namespace core
{
    struct model
    {
        std::vector<vertex::geometry<vertex::type::model>> geometries; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}