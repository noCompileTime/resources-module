#version 460

layout (location = 0) out vec4 out_color;

layout (std140, binding = 2) uniform ubo_material
{
    vec3 albedo_color;
};

void main()
{
    out_color = vec4(albedo_color, 1.0);
}