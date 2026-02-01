#pragma once

#include "core/model.hpp"

namespace models
{
    class ObjModel
    {
    public:
        static auto load(const std::filesystem::path& path) -> core::model;
    };
}