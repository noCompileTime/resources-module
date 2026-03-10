#include "obj_model.hpp"
#include "obj_parser.hpp"

namespace models
{
    auto ObjModel::load(const std::filesystem::path& path) -> core::model
    {
        core::model model;

        for (const auto data = ObjParser::parse(path); const auto& [name, indices] : data.objects)
        {
            uint32_t index = 0;

            core::data::geometry<core::vertex::type::model> geometry;

            for (const auto& [position, texcoord, normal] : indices)
            {
                geometry.vertices.emplace_back(data.positions[position], data.texcoords[texcoord], data.normals[normal]);
                geometry.elements.emplace_back(index++);
            }

            model.geometries.emplace_back(geometry);
        }

        return model;
    }
}