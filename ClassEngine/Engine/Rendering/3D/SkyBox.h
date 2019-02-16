#ifndef SKYBOX_H
#define SKYBOX_H

#include "Model.h"

using namespace std;
class SkyBox
{
public:
	SkyBox();
	//SkyBox(Shader * shaderProgram_, std::string tag_);
	~SkyBox();
	void CreateVertexBuffers();
	void Render();

	unsigned int loadTexture(char const * path);

	unsigned int loadCubemap(vector<std::string> faces);

	Shader* shader = new Shader("Engine/Shaders/cubemap.vs", "Engine/Shaders/cubemap.fs");
	Shader* skyboxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");
	unsigned int skyboxVAO, skyboxVBO, cubeVAO, cubeVBO, cubeTexture, cubemapTexture;
	Shader* ourShader;
};







#endif // !SKYBOX_H

