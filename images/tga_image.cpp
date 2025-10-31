#include "tga_image.hpp"
#include "tga_header.hpp"

namespace images
{
    auto TgaImage::load(const std::filesystem::path& path) -> core::data::image
    {
        tga_header header;

        std::ifstream stream(path, std::ios::binary);

        stream.read(reinterpret_cast<char*>(&header), sizeof(tga_header));

        const auto channels = header.pixel_depth / 8;
        const auto size = header.width * header.height * channels;


        std::vector<uint8_t> content(size);
        stream.read(reinterpret_cast<char*>(content.data()), size);

        for (auto i = 0; i < size; i += channels)
        {
            std::swap(content[i], content[i + 2]);
        }

        return
        {
            header.width,
            header.height,
            content
        };
    }
}