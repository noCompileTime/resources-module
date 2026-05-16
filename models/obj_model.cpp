#include "obj_model.hpp"
#include "obj_parser.hpp"

namespace models
{
    auto ObjModel::load(const std::filesystem::path& path) -> core::model
    {
        core::model model;
        // TODO use a reserve here based on the number of objects?

        for (const auto data = ObjParser::parse(path); const auto& [name, indices] : data.objects)
        {
            uint32_t index = 0;

            geometry::mesh<geometry::vertex::model> mesh;

            // TODO use geometry reserve here after checking the number of reallocation

            for (const auto& [position, normal, texcoord] : indices)
            {
                mesh.vertices.emplace_back(data.positions[position], data.normals[normal], data.texcoords[texcoord]);
                mesh.elements.emplace_back(index++); // TODO maybe here use a primitive to represent the triangle? to not do as many emplace_back?
            }

            model.meshes.emplace_back(std::move(mesh));
        }

        return model;
    }
}