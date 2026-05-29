#pragma once

#include "core/image.hpp"

#include <filesystem>
#include <fstream>

namespace images
{
    class TgaImage
    {
    public:
        [[nodiscard]] static auto load(const std::filesystem::path& path) -> core::image;
    };
}