#include "obj_parser.hpp"

#include <fstream>
#include <cassert>

namespace models
{
    auto ObjParser::parse(const std::filesystem::path& path) -> obj_data
    {
        obj_data data;

        assert(is_regular_file(path));

        std::ifstream stream(path);
        assert(stream.is_open());

        std::string line;
        while (std::getline(stream, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            std::string prefix;
            std::stringstream line_stream(line);

            line_stream >> prefix;

            if (prefix == "o")
            {
                auto& [name, indices] = data.objects.emplace_back();

                line_stream >> name;
            }
            else if (prefix == "v")
            {
                math::vec3     position;
                line_stream >> position.x >> position.y >> position.z;

                data.positions.emplace_back(position);
            }
            else if (prefix == "vn")
            {
                math::vec3     normal;
                line_stream >> normal.x >> normal.y >> normal.z;

                data.normals.emplace_back(normal);
            }
            else if (prefix == "vt")
            {
                math::vec2     texcoord;
                line_stream >> texcoord.x >> texcoord.y;

                data.texcoords.emplace_back(texcoord);
            }
            else if (prefix == "f")
            {
                std::string token;

                auto& [name, indices] = data.objects.back();

                while (line_stream >> token)
                {
                    std::string index;
                    std::stringstream token_stream(token);

                    obj_indices obj_indices;

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        obj_indices.position = std::stoi(index) - 1;
                    }

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        obj_indices.texcoord = std::stoi(index) - 1;
                    }

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        obj_indices.normal = std::stoi(index) - 1;
                    }

                    indices.emplace_back(obj_indices);
                }
            }
        }

        return data;
    }
}