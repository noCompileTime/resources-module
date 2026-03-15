#pragma once

#include "core/geometry.hpp"

namespace core
{
    struct model
    {
        std::vector<geometry<vertex::type::model>> geometries;
    };
}