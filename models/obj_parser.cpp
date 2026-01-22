#include "obj_parser.hpp"

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

            std::stringstream line_stream(line);
            std::string prefix;

            line_stream >> prefix;

            if (prefix == "o")
            {
                line_stream >> data.object_name;
            }
            else if (prefix == "v")
            {
                math::vec3 position;
                line_stream >> position.x >> position.y >> position.z;

                data.positions.emplace_back(position);
            }
            else if (prefix == "vn")
            {
                math::vec3 normal;
                line_stream >> normal.x >> normal.y >> normal.z;

                data.normals.emplace_back(normal);
            }
            else if (prefix == "vt")
            {
                math::vec2 texcoord;
                line_stream >> texcoord.u >> texcoord.v;

                data.texcoords.emplace_back(texcoord);
            }
            else if (prefix == "f")
            {
                std::string token;

                while (line_stream >> token)
                {
                    std::string part;
                    std::stringstream token_stream(token);

                    int32_t position, texcoord, normal;

                    if (std::getline(token_stream, part, '/') && !part.empty())
                    {
                        position = std::stoi(part) - 1;
                    }

                    if (std::getline(token_stream, part, '/') && !part.empty())
                    {
                        texcoord = std::stoi(part) - 1;
                    }

                    if (std::getline(token_stream, part, '/') && !part.empty())
                    {
                        normal = std::stoi(part) - 1;
                    }

                    data.faces.emplace_back(position, texcoord, normal);
                }
            }
        }

        return data;
    }
}