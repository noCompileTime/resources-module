#pragma once

#include "core/image.hpp"

namespace images
{
    class TgaImage
    {
    public:
        static auto load(const std::filesystem::path& path) -> core::image;
    };
}