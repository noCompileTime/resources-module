#include "obj_model.hpp"
#include "obj_parser.hpp"

namespace models
{
    auto ObjModel::load(const std::filesystem::path& path) -> core::model
    {
        const auto data = ObjParser::parse(path);

        core::model model;
                    model.geometries.reserve(data.objects.size());

        for (const auto& [name, indices] : data.objects)
        {
            uint32_t index = 0;

            mesh::model geometry;

            // TODO use geometry reserve here after checking the number of reallocation

            for (const auto& [position, normal, texcoord] : indices)
            {
                geometry.vertices.emplace_back(data.positions[position], data.normals[normal], data.texcoords[texcoord]);
                geometry.elements.emplace_back(index++); // TODO maybe here use a primitive to represent the triangle? to not do as many emplace_back?
            }

            model.geometries.emplace_back(std::move(geometry));
        }

        return model;
    }
}