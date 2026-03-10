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

            std::string prefix;
            std::stringstream line_stream(line);

            line_stream >> prefix;

            if (prefix == "o")
            {
                               data.objects.emplace_back();
                line_stream >> data.objects.        back().name;
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
                line_stream >> texcoord.u >> texcoord.v;

                data.texcoords.emplace_back(texcoord);
            }
            else if (prefix == "f")
            {
                std::string token;

                while (line_stream >> token)
                {
                    std::string index;
                    std::stringstream token_stream(token);

                    int32_t position, texcoord, normal;

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        position = std::stoi(index) - 1;
                    }

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        texcoord = std::stoi(index) - 1;
                    }

                    if (std::getline(token_stream, index, '/') && !index.empty())
                    {
                        normal = std::stoi(index) - 1;
                    }

                    data.objects.back().indices.emplace_back(position, texcoord, normal);
                }
            }
        }

        return data;
    }
}