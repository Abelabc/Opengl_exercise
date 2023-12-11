#version 330 core
layout (location = 0) in vec3 aPos;//它将vPosition的位置属性location设置为0，为它提供了元数据。
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 textcoord;
uniform float xyoffset[];
uniform mat4 transform;
out vec3 ourColor;
out vec2 Texcoord;
void main()
{
    gl_Position = transform*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor;
    Texcoord = textcoord;

}