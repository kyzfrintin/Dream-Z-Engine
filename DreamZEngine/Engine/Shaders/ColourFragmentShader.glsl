#version 330 core

struct Light{
	vec3 lightPos;
	float ambient;
	float diffuse;
	vec3 lightColor;
};

in vec2 TexCoords;
in vec3 FragPosition;
in vec3 Normal;

uniform sampler2D inputTexture;
uniform Light light;
uniform vec3 viewPosition;

out vec4 color;

void main(){

	//ambient
	vec3 ambient = light.ambient * texture(inputTexture, TexCoords).rgb * light.lightColor;

	//diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.lightPos - FragPosition);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * texture(inputTexture, TexCoords).rgb * light.lightColor;

	//specular
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPosition * FragPosition);
	vec3 reflectedDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectedDir), 0.0f), 32.0f);
	vec3 specular = specularStrength * spec * light.lightColor;

	vec3 result = ambient + diffuse + specular;

	color = vec4(result, 1.0f);
}