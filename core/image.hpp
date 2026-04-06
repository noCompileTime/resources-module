#pragma once

namespace core
{
    struct image
    {
        std::int32_t width;
        std::int32_t height;
        std::int32_t channels;

        std::vector<uint8_t> pixels;
    };
}