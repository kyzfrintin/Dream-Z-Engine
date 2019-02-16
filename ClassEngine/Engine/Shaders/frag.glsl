#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} fs_in;



struct LightStruct {

	vec3 color	  ;
	vec3 direction;
	vec3 position;
	vec3 ambient ;
	vec3 diffuse ;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
	vec3 cutOff ;
	vec3 outerCutOff ;

};
#define lightsize 3

uniform int lightsizes;
uniform sampler2D floorTexture;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform LightStruct lights[3];
uniform bool blinn;

vec3 CalculateLights(LightStruct light);

void main()
{           

   vec3 result;
   for(int i=0; i<1;i++)
   result+= CalculateLights(lights[i]);
    
    FragColor = vec4(result, 1.0);
	
}

vec3 CalculateLights(LightStruct light)
{
	vec3 color = texture(floorTexture, fs_in.TexCoords).rgb;
    // ambient
    vec3 ambient =  (0.05 * color);
    // diffuse
    vec3 lightDir = normalize(light.position - fs_in.FragPos);
    vec3 normal = normalize(fs_in.Normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse =  (diff * color);
    // specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    if(blinn)
    {
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    }
    else
    {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
    }
    vec3 specular = (vec3(0.3) * spec); // assuming bright white light color
	return (ambient+diffuse+specular);
}
