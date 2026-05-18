#pragma once

#include "geometry/mesh.hpp"
#include "geometry/vertex/model.hpp"

namespace core
{
    struct model
    {
        std::vector<geometry::mesh<geometry::vertex::model>> meshes; // TODO here to have a map? or a flat map? to seach stuff by name?
    };
}