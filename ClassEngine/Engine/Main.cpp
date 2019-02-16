#include "Core/EngineClass.h"
#include "../Game/Game1.h"



int main(int argc, char* args[])
{
	
	//Version 1
	/*if (!EngineClass::GetInstance()->Initialize("FartBox", 800, 600))
	{
		
		return 0;
	}*/

	//VERSION 2
	EngineClass::GetInstance()->SetGameInterface(new Game1());
	EngineClass::GetInstance()->Initialize("FartBox", 800, 600);
	EngineClass::GetInstance()->Run();

	return 0;
}