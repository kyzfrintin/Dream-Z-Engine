#include "Game1.h"



Game1::Game1()
{
}

Game1::~Game1()
{
	sceneManager = nullptr;
}

bool Game1::Initialize()
{
	// Make reference to the scene manager
	sceneManager = EngineClass::GetInstance()->GetSceneManager();

	// If you plan to use the scenemanagers scene vector you dont need to set these values all the time
	// Set camera options
	cameraList[0]->Yaw = 0.0f;
	cameraList[0]->Zoom = 45.0f;

	// Set screen options
	sceneManager->EnableSplitscreen(false);
	sceneManager->EnableFullscreen(false);
	sceneManager->ShowFPS(true);
	sceneManager->GetRenderer()->EnableBloom(true);

	// Load shaders
	defaultShader = new Shader("Engine/Shaders/model.vs", "Engine/Shaders/model.fs");
	skyboxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");

	//// Put shaders into shader manager
	//defaultShaderHandle = sceneManager->GetRenderer()->GetShaderManager()->put(std::string("default"), defaultShader);
	//skyboxShaderHandle = sceneManager->GetRenderer()->GetShaderManager()->put(std::string("skybox"), skyboxShader);

	// Make skybox, load its textures, set properties, and give to the renderer
	//skybox = new Skybox();
	//std::vector<std::string> faces;
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/right.jpg");
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/left.jpg");
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/top.jpg");
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/bottom.jpg");
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/back.jpg");
	//faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/front.jpg");
	//skybox->LoadTextures(faces);
	//skybox->SetShader(skyboxShader);

	

	//kyouko = new Model("Resources/Models/Kyouko/figyrk0003.obj");
	//kyouko = new Model("Resources/Models/Robot_Base_Greybox/Robot_Var_002_Gurran.obj");
	kyouko = new Model("Resources/Models/Robot_Base_Greybox/Robot_Var_002_Gurran.obj");
	kyouko->SetShader(defaultShader);
	kyouko->physicsComponent->SetPosition(glm::vec3(-1.0f, -1.0f, -2.5f));
	kyouko->SetWorldScale(0.008f);
	kyouko->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	kyouko->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	kyouko->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	kyouko->physicsComponent->SetMass(0.0f);

	kyouko2 = new Model("Resources/Objects/pen/Capoeira.fbx");
	kyouko2->SetShader(defaultShader);
	kyouko2->physicsComponent->SetPosition(glm::vec3(1.0f, -1.0f, -2.5f));
	kyouko2->SetWorldScale(0.008f);
	kyouko2->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	kyouko2->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	kyouko2->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	kyouko2->physicsComponent->SetMass(0.0f);

	// Lights
	//
	// Make point light
	pointLight = new Light();
	pointLight->SetShader(defaultShader);
	pointLight->renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
	pointLight->renderComponent->SetColour(1.0f, 1.0f, 1.0f);
	pointLight->renderComponent->CanRender(false);
	pointLight->SetWorldPosition(2.0f, 0.0f, -2.5f);
	pointLight->SetWorldScale(0.5f);
	pointLight->lightComponent->SetLightType(LightComponent::Light_Type::POINTLIGHT);
	pointLight->lightComponent->SetColour(glm::vec3(1.0f, 1.0f, 1.0f));
	//

	// Make directional light
	dirLight = new Light(LightComponent::Light_Type::DIRECTIONAL);
	dirLight->lightComponent->SetDirection(glm::vec3(1.0f, -1.0f, 1.0f));
	dirLight->lightComponent->SetColour(glm::vec3(0.3f, 0.3f, 0.3f));
	//

	AddObject(kyouko);
	AddObject(kyouko2);
	AddLightObject(dirLight);
	AddLightObject(pointLight);

	
	return true;
}

void Game1::Update(const float deltaTime)
{
	float fade = (sin(z += deltaTime) / 2.0f) + 0.5f;
	//startText->SetAlpha(fade);
	//cameraList[0]->SetRotationX(cameraList[0]->Yaw += deltaTime * 5);


}

void Game1::FixedUpdate(const float deltaTime)
{
	kyouko->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), kyouko->GetWorldRotationAngle() + 2.0f * deltaTime);
	kyouko2->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), kyouko->GetWorldRotationAngle() + -2.0f * deltaTime);
}

void Game1::HandleEvents(SDL_Event events)
{
	
}

void Game1::HandleStates(const Uint8 *state)
{
	if (state[SDL_SCANCODE_SPACE]) {
		sceneManager->NextScene();
	}
}