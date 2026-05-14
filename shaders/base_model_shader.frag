#version 460 core

layout (location = 0) in vec3 in_normal;
layout (location = 1) in vec2 in_texcoord;
//layout (location = 2) in vec3 in_position;

layout (location = 0) out vec4 out_color;

layout (location = 0) uniform sampler2D u_albedo_texture;

layout (binding = 2, std140) uniform material_ubo
{
    vec3 albedo_color;
};

layout (binding = 3, std140) uniform light_ubo
{
    vec3  color;
    float ambient;
    vec3  extra;
} u_light;

void main()
{
    vec3 normal    = normalize(in_normal);
    vec3 direction = normalize(-u_light.extra);

    vec3 ambient_color = u_light.color * u_light.ambient;
    vec3 diffuse_color = u_light.color * max(dot(normal, direction), 0.0);

    vec4 light_color = vec4(ambient_color + diffuse_color, 1.0);
    vec4 model_color = texture(u_albedo_texture, in_texcoord); // TODO add the albedo_color here

    out_color = light_color * model_color;
}