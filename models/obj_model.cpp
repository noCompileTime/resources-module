#include "obj_model.hpp"
#include "obj_parser.hpp"

namespace models
{
    auto ObjModel::load(const std::filesystem::path& path) -> core::data::model
    {
        uint32_t index = 0;

        core::data::geometry<core::vertex::type::model> geometry;

        for (const auto data = ObjParser::parse(path); const auto& [position, texcoord, normal] : data.indices)
        {
            geometry.vertices.emplace_back(data.positions[position],
                                           data.texcoords[texcoord],
                                           data.normals  [normal]);

            geometry.elements.emplace_back(index++);
        }

        core::data::model model;
                          model.geometry = geometry;
        return model;
    }
}