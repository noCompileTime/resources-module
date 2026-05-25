#pragma once

namespace core
{
    struct image // TODO can this go in common? should go inside common?
    {
        int32_t width;
        int32_t height;
        int32_t channels;

        std::vector<uint8_t> pixels;
    };
}