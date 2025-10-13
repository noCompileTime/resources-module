#pragma once

namespace editor
{
    class ShadersConverter
    {
    public:
        static auto convert_file(const std::filesystem::path& input, const std::filesystem::path& output) -> void;
    };
}