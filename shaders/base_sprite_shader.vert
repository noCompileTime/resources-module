#version 460 core

layout (location = 0) in vec2 in_position;
layout (location = 1) in vec2 in_texcoord;

layout (binding = 0, std140) uniform ubo_camera
{
    mat4 view;
    mat4 projection;
};

layout (binding = 1, std140) uniform ubo_transform
{
    mat4 model;
};

layout (location = 0) out vec2 out_texcoord;

void main()
{
     gl_Position = projection * view * model * vec4(in_position, 0.0, 1.0);

    out_texcoord = in_texcoord;
}