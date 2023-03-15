#include "DXEngine.h"
#pragma comment (lib,"d3dx9.lib")


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow) {
	DXEngine* Engine = new DXEngine(1200, 900);
	if (!Engine)
		return 0;

	if (!Engine->Initialize()) {
		return 0;
	}

	Engine->Run();
	Engine->Shutdown();
	delete Engine;
	Engine = 0;

	return 0;
}