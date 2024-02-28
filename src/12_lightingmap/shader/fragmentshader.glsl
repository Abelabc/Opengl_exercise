#version 330 core
struct Material {
    //vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};
struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float constant;
    float linear;
    float quadratic;
};
uniform vec3 viewPos;
uniform Light light;
uniform Material material;
out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;
void main()
{
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    // 漫反射
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    // 镜面光
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular *spec*  texture(material.specular, TexCoords).rgb;
    // attenuation
    float distance    = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // ambient  *= attenuation; // remove attenuation from ambient, as otherwise at large distances the light would be darker inside than outside the spotlight due the ambient term in the else branch
    diffuse   *= attenuation;
    specular *= attenuation;
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}