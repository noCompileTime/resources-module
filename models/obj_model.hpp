#pragma once

#include "core/data/model.hpp"

namespace models
{
    class ObjModel
    {
    public:
        static auto load(const std::filesystem::path& path) -> core::data::model;
    };
}