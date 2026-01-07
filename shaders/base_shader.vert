#version 460 core

layout (location = 0) in vec3 in_position;

layout (binding = 0, std140) uniform ubo_camera
{
    mat4 view;
    mat4 projection;
};

layout (binding = 1, std140) uniform ubo_transform
{
    mat4 model;
};

void main()
{
    gl_Position = projection * view * model * vec4(in_position, 1.0);
}