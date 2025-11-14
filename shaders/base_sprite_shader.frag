#version 460

layout (location = 0) in vec2 in_texcoord;

layout (location = 0) uniform sampler2D u_albedo_texture;

layout (location = 0) out vec4 out_color;

void main()
{
    out_color = texture(u_albedo_texture, in_texcoord);
}