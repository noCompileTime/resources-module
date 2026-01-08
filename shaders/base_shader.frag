#version 460 core

layout (location = 0) out vec4 out_color;

layout (binding = 2, std140) uniform ubo_material
{
    vec3 albedo_color;
};

void main()
{
    out_color = vec4(albedo_color, 1.0);
}