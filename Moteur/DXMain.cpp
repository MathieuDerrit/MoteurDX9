#include "DXEngine.h"


int WINAPI WinMain2(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)
{
	//Credit our game engine with window size, default is 800 by 600 pixels through default constructor
	DXEngine* Engine = new DXEngine(800, 700);
	if (!Engine)
		return 0;

	if (!Engine->Initialize())
	{
		return 0;
	}

	//Loop that will run until the escape key is pressed
	Engine->Run();

	//Cleanup the engine
	Engine->Shutdown();
	delete Engine;
	Engine = 0;

	return 0;
}