#pragma once

namespace tools
{
    class ShadersConverter
    {
    public:
        static auto convert_each(const std::filesystem::path& input, const std::filesystem::path& output) -> void;
        static auto convert_file(const std::filesystem::path& input, const std::filesystem::path& output) -> void;

        ShadersConverter() = delete;
    };
}