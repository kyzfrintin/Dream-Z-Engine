#ifndef GAME1_H
#define GAME1_H

#include "../Engine/Core/EngineClass.h"
#include <glm/gtx/string_cast.hpp>
#include "../Engine/Core/GameInterface.h"
#include "../Engine/Rendering/3D/Model.h"
#include "../Engine/Rendering/SceneGraph.h"
#include "../Engine/Rendering/3D/Terrain.h"
#include "../Engine/Rendering/3D/SkyBox.h"
#include "../Engine/FX/BasicLight.h"
#include "../Engine/Rendering/3D/Cube.h"

class Game1 : public GameInterface
{
public:
	Game1();
	virtual~Game1();


	virtual bool Initialize();
	virtual void Update(const float deltaTime);
	virtual void Render();
	//AudioManager* aEngine;
	SkyBox* skybox;
	Terrain* terrain;
	Model* model;
	Model* model2;
	BasicLight* lamp;
	BasicLight* lamp2;
	BasicLight* lamp3;
	// camera
	Cube* cb;

private:

};





#endif // !GAME1_H


