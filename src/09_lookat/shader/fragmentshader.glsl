#version 330 core
out vec4 FragColor;
in vec2 Texcoord;

uniform sampler2D texture2;
uniform float mixValue;

void main() {
    FragColor = texture(texture2, Texcoord) ;
    //FragColor = texture(texture1, Texcoord);
}