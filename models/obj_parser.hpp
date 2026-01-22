#pragma once

#include "obj_data.hpp"

namespace models
{
    class ObjParser
    {
    public:
        static auto parse(const std::filesystem::path& path) -> obj_data;
    };
}