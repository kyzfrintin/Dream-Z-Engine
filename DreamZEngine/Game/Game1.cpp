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

	lamp = new BasicLight(lampShader, "pointLight1");
	//cb = new Cube(lampShader, "collision", model->GetBoundingBox().minVert,model->GetBoundingBox().maxVert);
	terrain = new Terrain(ourShader);
	skybox = new SkyBox();
	LightStruct* pointLights1 = new LightStruct();
	pointLights1->position = (glm::vec3(0.0f, 0.0f, 0.0f));
	//LightStruct* pointLights2 = new LightStruct();
	//pointLights2->position = (glm::vec3(2.2f, 0.0f, 2.0f));
	//LightStruct* pointLights3 = new LightStruct();
	//pointLights3->position = (glm::vec3(-2.2f, 0.0f, 2.0f));

	//SceneGraph::GetInstance()->AddLight(lamp, lamp->tag, pointLights1);
	//SceneGraph::GetInstance()->AddCollider(cb);
	////SceneGraph::GetInstance()->AddLight(lamp3, lamp3->tag, pointLights3);
	//SceneGraph::GetInstance()->AddGameObject(new GameObject(cb), "collision");
	//SceneGraph::GetInstance()->GetGameObject("collision")->SetScale(glm::vec3(2.0f));
	


	SceneGraph::GetInstance()->AddSkybox(skybox);
	SceneGraph::GetInstance()->AddTerain(terrain);

	//AudioHandler::GetInstance()->AddAudio("song","pop.wav", AudioEnum::MUSIC);

	//AudioLoader::GetInstance()->PlayMusic("UpbeatFunk.WAV");

	SceneGraph::GetInstance()->AddModel(model);
	SceneGraph::GetInstance()->AddGameObject(new GameObject(model), "nano");
	SceneGraph::GetInstance()->GetGameObject("nano")->SetPosition(glm::vec3(5.0f, 0.75f, -5.0f));
	SceneGraph::GetInstance()->GetGameObject("nano")->SetScale(glm::vec3(0.5f));

	/*std::cout << "Object 1 bounding box: " << std::endl;
	std::cout << "\tMin Vert: " << glm::to_string(SceneGraph::GetInstance()->GetGameObject("nano")->GetBoundingBox().minVert) << std::endl;
	std::cout << "\tMax Vert: " << glm::to_string(SceneGraph::GetInstance()->GetGameObject("nano")->GetBoundingBox().maxVert) << std::endl;

	std::cout << "Object 2 bounding box: " << std::endl;
	std::cout << "\tMin Vert: " << glm::to_string(SceneGraph::GetInstance()->GetGameObject("collision").) << std::endl;
	std::cout << "\tMax Vert: " << glm::to_string(SceneGraph::GetInstance()->GetGameObject("collision")->GetBoundingBox().maxVert) << std::endl;*/

	return true;
}



void Game1::Update(const float deltaTime_)
{

	

}
void Game1::Render()
{

	//cb->Render();
	//	terrain->Render();
	SceneGraph::GetInstance()->Render();
	//model->Render();
}