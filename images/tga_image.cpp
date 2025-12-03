#include "tga_image.hpp"
#include "tga_header.hpp"

namespace images
{
    auto TgaImage::load(const std::filesystem::path& path) -> core::data::image
    {
        tga_header header;

      assert(is_regular_file(path));

        std::ifstream stream(path, std::ios::binary);
               assert(stream.is_open());

        stream.read(reinterpret_cast<char*>(&header), sizeof(tga_header));
                            assert(stream.gcount() == sizeof(tga_header));

        const auto channels = header.pixel_depth  / 8;
        const auto     size = header.width * header.height * channels;

                       std::vector<uint8_t> content(size);
        stream.read(reinterpret_cast<char*>(content.data()),  size);
                                    assert(stream.gcount() == size);

        for (auto i = 0; i < size; i += channels)
        {
            std::swap(content[i], content[i + 2]);
        }

        return
        {
            content,
            header.width,
            header.height,
            channels
        };
    }
}