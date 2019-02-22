#ifndef ENGINECLASS_H
#define ENGINECLASS_H


#include "Window.h"
#include"Timer.h"
#include "GameInterface.h"
#include "../Camera/Camera.h"
#include "../Audio/AudioHandler.h"
#include "../Audio/AudioLoader.h"
#include "../Events/EventListener.h"
#include <memory>
#include <map>
#include <vector>


class EngineClass
{
public:
	EngineClass(const EngineClass&) = delete;
	EngineClass(EngineClass&&) = delete;
	EngineClass& operator=(const EngineClass&) = delete;
	EngineClass& operator=(EngineClass&&) = delete;


	bool Initialize(std::string name_, int width_, int height_);
	void Run();
	bool GetIsRunning();
	void SetGameInterface(GameInterface* gameInterface_);

	glm::vec2 GetScreenSize() const;
	void NotifyOfMousePressed(int x_, int y_);
	void NotifyOfMouseReleased(int x_, int y_,int buttonType_);
	void NotifyOfMouseMoved(int x_, int y_ );
	void NotifyOfMouseScroll(int y_ );
	void ExitGame();
	static EngineClass* GetInstance();

private:

	EngineClass();
	~EngineClass();

	static std::unique_ptr<EngineClass> engineInstance;
	friend std::default_delete<EngineClass>;

	void Update(const float deltaTime_);
	void Render();
	void Shutdown();

	Window* window;
	Timer timer;
	GameInterface* gameInterface;
	bool isRunning;
	unsigned int fps;

};




#endif // !ENGINECLASS_H

