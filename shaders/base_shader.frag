#version 460

layout (binding  = 2, std140) uniform ubo_material
{
    vec3 albedo_color;
};

layout (location = 0) out vec4 out_color;

void main()
{
    out_color = vec4(albedo_color, 1.0);
}