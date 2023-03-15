#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include "DXGraphics.h"
#pragma comment (lib, "d3dx9.lib")

class DXEngine
{
public:
	void Engine();
	void Engine(int width, int height);

	bool Initialize();
	void Run();
	bool Frame();
	bool Shutdown();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool InitializeWindow(HWND hwnd, int& screenWidth, int& screenHeight);
	bool ShutdownWindow();

	DXGraphics* Graphics;
	//EngineInput* Input;

	HWND m_hwnd;
	HINSTANCE m_hinstance;
	int windowWidth, windowHeight;
};

static DXEngine* ApplicationHandle = 0;
static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

