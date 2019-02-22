#include "EngineClass.h"

std::unique_ptr<EngineClass> EngineClass::engineInstance;

EngineClass::EngineClass() : window(nullptr), isRunning(false), fps(120), gameInterface(nullptr){
}


EngineClass::~EngineClass(){
}

EngineClass* EngineClass::GetInstance() {

	if (engineInstance.get() == nullptr) {

		engineInstance.reset(new EngineClass);
	}

	return engineInstance.get();
}

bool EngineClass::Initialize(std::string name_, int width_, int height_) {
	Debug::DebugInit();
	Debug::SetSeverity(MessageType::TYPE_INFO);

	window = new Window();

	if (!window->Initialize(name_, width_, height_)) {
		Debug::FatalError("Failed to initialize window object", __FILE__, __LINE__);
		return isRunning = false;
	}
	SDL_WarpMouseInWindow(window->GetWindow(), window->GetWidth() / 2, window->GetHeight() / 2);

	
	MouseEventListener::RegisterEngineObject(this);

	if (gameInterface) {
		if (!gameInterface->Initialize()) {
			Debug::FatalError("Failed to initialize game interface", __FILE__, __LINE__);
			return isRunning = false;
		}
	}

	timer.Start();
	Debug::Info("Everything initialized fine in EngineClass", __FILE__, __LINE__);

	return isRunning = true;
}

void EngineClass::Run() {

	while (isRunning) {
		EventListener::Update(timer.GetDeltaTime());
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}

	if (!isRunning) {
		Shutdown();
	}
}

void EngineClass::Update(const float deltaTime) {

	
	if (gameInterface) {
		gameInterface->Update(deltaTime);
	}
	
}

void EngineClass::Render() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gameInterface) {
		gameInterface->Render();
	}

	SDL_GL_SwapWindow(window->GetWindow());
}

bool EngineClass::GetIsRunning() {
	return isRunning;
}

void EngineClass::Shutdown() {

	delete window;
	window = nullptr;
	//change messing
	if (!gameInterface)
	{
		delete gameInterface;
		gameInterface = nullptr;
	}
	

	SDL_Quit();

	exit(0);
}

void EngineClass::SetGameInterface(GameInterface* gameInterface_) {
	gameInterface = gameInterface_;
}

glm::vec2 EngineClass::GetScreenSize() const{
	return glm::vec2(window->GetWidth(), window->GetHeight());
}




void EngineClass::NotifyOfMousePressed(int x_, int y_) {
}

void EngineClass::NotifyOfMouseReleased(int x_, int y_, int buttonType_) {
//	CollisionHandler::GetInstance()->Update(glm::vec2(x_, y_), buttonType_);
}

void EngineClass::NotifyOfMouseMoved(int x_, int y_) {
	//Camera::GetInstance()->ProcessMouseMovement(MouseEventListener::GetMouseOffset().x,MouseEventListener::GetMouseOffset().y);
}

void EngineClass::NotifyOfMouseScroll(int y_) {
	//Camera::GetInstance()->ProcessMouseZoom(y_);
}

void EngineClass::ExitGame() {
	isRunning = false;
}