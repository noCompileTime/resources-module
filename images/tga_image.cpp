#include "tga_image.hpp"
#include "tga_header.hpp"

namespace images
{
    auto TgaImage::load(const std::filesystem::path& path) -> core::image
    {
        tga_header header;

        assert(is_regular_file(path)); // TODO handle different if there is no file

        std::ifstream stream(path, std::ios::in | std::ios::binary);
               assert(stream);

        stream.read(reinterpret_cast<char*>(&header), sizeof(tga_header));

        assert(stream.gcount() == sizeof(tga_header)); // TODO handle different if there is a corrupted tga

        const auto channels = header.pixel_depth / 8;
        const auto     size = header.width * header.height * channels;
        std::vector<uint8_t> content(size);

        stream.read(reinterpret_cast<char*>(content.data()), size);

        assert(stream.gcount() == static_cast<std::streamsize>(size)); // TODO handle different if there is a corrupted tga

        for (auto i = 0; i < size; i += channels)
        {
            std::swap(content[i], content[i + 2]);
        }

        return
        {
            header.width,
            header.height, channels, std::move(content)
        };
    }
}