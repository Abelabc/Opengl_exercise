#version 330 core
layout (location = 0) in vec3 aPos;//它将vPosition的位置属性location设置为0，为它提供了元数据。
layout (location = 1) in vec2 textcoord;
uniform float xyoffset[];
uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec2 Texcoord;
void main()
{
    //gl_Position = transform*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    gl_Position = projection* view*model* vec4(aPos.x, aPos.y, aPos.z, 1.0);
    Texcoord = textcoord;
}