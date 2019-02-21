#ifndef CUBE_H

#define CUBE_H



#include "Model.h"
#include "../../FX/LightingManager.h"
class Cube
{
public:
	Cube(Shader* shaderProgram_, std::string tag_, glm::vec3 min_, glm::vec3 max_);
	~Cube();

	Shader* ourShader;

	GLuint CreateCubeInstance(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);

	void UpdateInstance(GLuint index_, glm::vec3  position_, float angle_, glm::vec3 rotation, glm::vec3 scale_);
	glm::mat4 GetTransform(GLuint index_) const;
	glm::mat4 GetTransform(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
	std::string tag;
	void CreateVertexBuffers();
	void Render();
	GLuint loadTexture(char const * path);
	GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO, diffuseMap, specularMap;
	//GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO;

	Shader* GetShader() { return ourShader; }
	glm::vec3 min, max;
	Shader lampShader = Shader("Engine/Shaders/lampVert.glsl", "Engine/Shaders/lampFrag.glsl");
	Shader lightingShader = Shader("Engine/Shaders/colorVert.glsl", "Engine/Shaders/colorFrag.glsl");
private:
	std::vector<glm::mat4> modelInstances;
	glm::vec3 lightPos = glm::vec3(0.2f, 0.0f, 2.0f);
};




#endif // !TERRAIN_H


