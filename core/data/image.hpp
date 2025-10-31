#pragma once

namespace core::data
{
    struct image
    {
        int32_t  width  { };
        int32_t  height { };

        std::vector<uint8_t> data;
    };
}