#pragma once

#include "core/image.hpp"

#include <filesystem>

namespace images
{
    class TgaImage
    {
    public:
        [[nodiscard]] static auto load(const std::filesystem::path& path) -> core::image;
    };
}