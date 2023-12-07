#version 330 core
layout (location = 0) in vec3 aPos;//它将vPosition的位置属性location设置为0，为它提供了元数据。
layout (location = 1) in vec3 aColor;
uniform float xyoffset[];
out vec3 ourColor;
void main()
{
    gl_Position = vec4(aPos.x+xyoffset[0],xyoffset[1] -aPos.y, aPos.z, 1.0);
    ourColor =aColor;
}