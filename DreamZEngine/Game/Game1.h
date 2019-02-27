#pragma once
#ifndef GAME1_H
#define GAME1_H

#include "../Engine/Core/EngineClass.h"
#include "../Engine/Core/Scene.h"
#include "../Engine/Core/Light.h"
#include "../Engine/Rendering/3D/Model.h"
//#include "../Engine/Core\ResourceManager.h"
#include "../Engine/Rendering/3D/SkyBox.h"
#include "../Engine/Graphics\Shader.h"
//#include "../Engine/Rendering\2D\TextUI.h"
//#include "../Engine/Rendering\2D\ImageUI.h"
//#include "../Engine/Rendering\2D\ButtonUI.h"
//#include "DemoScene.h"
//#include "TestScene.h"
//#include "MenuSelectScene.h"




	class Game1 : public Scene
	{
	public:
		Game1();
		~Game1();

		// Every scene requires these three methods to be implemented
		bool Initialize();
		void Update(const float deltaTime);
		void FixedUpdate(const float deltaTime);
		void HandleEvents(SDL_Event events);
		void HandleStates(const Uint8 *state);

		SceneManager* sceneManager;
	private:
		// shaders
		Shader* skyboxShader;
		Shader* defaultShader;

		// shader handles / reference to shader in the renderers shader manager
		//ResourceHandle<Shader> skyboxShaderHandle;
		Model* kyouko;
		Model* kyouko2;

		// Lights
		Light* pointLight;
		Light* dirLight;
		// UI
		/*TextUI* titleText;
		TextUI* startText;
		TextUI* creditText;*/

		float z = 0;
	};

#endif

