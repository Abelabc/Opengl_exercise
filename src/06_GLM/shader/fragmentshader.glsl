#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 Texcoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main() {
    FragColor = mix(texture(texture1, Texcoord), texture(texture2, Texcoord), mixValue);
    //FragColor = texture(texture1, Texcoord);
}