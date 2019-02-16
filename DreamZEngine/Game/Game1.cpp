#include "Game1.h"



Game1::Game1()
{

}


Game1::~Game1()
{


	//delete object1;

}

bool Game1::Initialize()
{

	
	Shader* ourShader = new Shader("Engine/Shaders/vert.glsl", "Engine/Shaders/frag.glsl");
	Shader* modelShader = new Shader("Engine/Shaders/modelVert.glsl", "Engine/Shaders/modelFrag.glsl");
	Shader* lampShader = new Shader("Engine/Shaders/lampVert.glsl", "Engine/Shaders/lampFrag.glsl");
	Shader* skyBoxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");
	model = new Model(modelShader, "Resources/Objects/nanosuit/nanosuit.obj");

	terrain = new Terrain(ourShader);

	lamp = new BasicLight(lampShader, "pointLight1");
	lamp2 = new BasicLight(lampShader, "pointLight2");
	lamp3 = new BasicLight(lampShader, "pointLight3");

	skybox = new SkyBox();
	LightStruct* pointLights1 = new LightStruct();
	pointLights1->position = (glm::vec3(1.2f, 0.0f, 2.0f));
	LightStruct* pointLights2 = new LightStruct();
	pointLights2->position = (glm::vec3(2.2f, 0.0f, 2.0f));
	LightStruct* pointLights3 = new LightStruct();
	pointLights3->position = (glm::vec3(-2.2f, 0.0f, 2.0f));

	SceneGraph::GetInstance()->AddLight(lamp, lamp->tag, pointLights1);
	//SceneGraph::GetInstance()->AddLight(lamp2, lamp2->tag, pointLights2);
	//SceneGraph::GetInstance()->AddLight(lamp3, lamp3->tag, pointLights3);
	SceneGraph::GetInstance()->AddGameObject(new GameObject(lamp), lamp->tag);
	//SceneGraph::GetInstance()->AddGameObject(new GameObject(lamp2), lamp2->tag);
	//SceneGraph::GetInstance()->AddGameObject(new GameObject(lamp3), lamp3->tag);


	SceneGraph::GetInstance()->AddSkybox(skybox);
	SceneGraph::GetInstance()->AddTerain(terrain);

	//AudioHandler::GetInstance()->AddAudio("song","pop.wav", AudioEnum::MUSIC);

	AudioLoader::GetInstance()->PlayMusic("UpbeatFunk.WAV");

	SceneGraph::GetInstance()->AddModel(model);
	SceneGraph::GetInstance()->AddGameObject(new GameObject(model), "test3");
	//SceneGraph::GetInstance()->GetGameObject("test3")->SetPosition(glm::vec3(0.0f, -1.75f, 0.0f));
	SceneGraph::GetInstance()->GetGameObject("test3")->SetScale(glm::vec3(1.0f));


	return true;
}



void Game1::Update(const float deltaTime_)
{

	

}
void Game1::Render()
{
	//	terrain->Render();
	SceneGraph::GetInstance()->Render();
	//model->Render();
}