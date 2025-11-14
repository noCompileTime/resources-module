#version 460

layout (location = 0) in vec3 in_position;

layout (std140, binding = 0) uniform ubo_camera
{
    mat4 view;
    mat4 projection;
};

layout (std140, binding = 1) uniform ubo_transform
{
    mat4 model;
};

void main()
{
    gl_Position = projection * view * model * vec4(in_position, 1.0);
}