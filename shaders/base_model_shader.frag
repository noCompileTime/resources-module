#version 460 core

layout (location = 0) in vec2 in_texcoord;
layout (location = 1) in vec3 in_normal;

layout (location = 0) out vec4 out_color;

layout (location = 0) uniform sampler2D u_albedo_texture;

layout (binding = 2, std140) uniform ubo_material
{
    vec3 albedo_color;
};

void main()
{
    out_color = texture(u_albedo_texture, in_texcoord);
}