#pragma once

#include "core/geometry.hpp"

namespace core
{
    struct model
    {
        std::vector<geometry<vertex::type::model>> geometries; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}