#include "shaders_converter.hpp"

namespace editor
{
    auto ShadersConverter::convert_file(const std::filesystem::path& input, const std::filesystem::path& output) -> void
    {
        const auto out = output / input.filename();

        if (const auto ext  = input.extension().string();
                       ext == ".vert" || ext == ".frag")
        {
            const auto cmd = std::format("glslangvalidator -V -G -S {} -o {} {}", ext.substr(1), out.string(), input.string());
            const auto err = std::system(cmd.c_str());

               assert(!err);
        }
    }
}