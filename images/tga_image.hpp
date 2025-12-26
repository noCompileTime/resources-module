#pragma once

#include "core/data/image.hpp"

namespace images
{
    class TgaImage
    {
    public:
        static auto load(const std::filesystem::path& path) -> core::data::image;
    };
}