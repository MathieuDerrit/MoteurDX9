#include "DXEngine.h"

void DXEngine::Engine()
{
	//this->Graphics = 0;
	//this->Input = 0;
	this->m_hwnd = 0;
	this->m_hinstance = GetModuleHandle(NULL);
	this->windowWidth = 800;
	this->windowHeight = 600;
}

void DXEngine::Engine(int width, int height)
{
	//this->Graphics = 0;
	this->m_hwnd = 0;
	this->m_hinstance = GetModuleHandle(NULL);
	this->windowWidth = width;
	this->windowHeight = height;
}

bool DXEngine::Initialize()
{
	//int screenWidth, screenHeight;
	//bool result = this->InitializeWindow(this->m_hwnd, screenWidth, screenHeight);

	//this->Graphics = new EngineGraphics;
	//if (!Graphics)
	//	return false;

	//if (!Graphics->InitializeGraphics(this->m_hwnd, this->windowWidth, this->windowHeight))
	//{
	//	return false;
	//}

	//this->Input = new EngineInput;
	//if (!Input)
	//	return false;

	//if (!Input->Initialize())
	//{
	//	return false;
	//}

	//return true;
}

void DXEngine::Run()
{
	bool running = true;
	MSG msg;

	while (running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
			running = false;

		if (!this->Frame())
			running = false;
	}
}

bool DXEngine::Frame()
{
	return false;
}

bool DXEngine::Shutdown()
{
	return false;
}

LRESULT DXEngine::MessageHandler(HWND, UINT, WPARAM, LPARAM)
{
	return LRESULT();
}

bool DXEngine::InitializeWindow(HWND hwnd, int& screenWidth, int& screenHeight)
{
	ApplicationHandle = this;

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = this->m_hinstance;
	wc.lpszClassName = L"gameclass";
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(this->m_hinstance, IDC_CROSS);
	wc.lpfnWndProc = WindowProc;
	RegisterClassEx(&wc);

	int screenX = (GetSystemMetrics(SM_CXSCREEN) - this->windowWidth) / 2;
	int screenY = (GetSystemMetrics(SM_CYSCREEN) - this->windowHeight) / 2;

	this->m_hwnd = CreateWindowEx(NULL, L"gameclass", L"Game Engine", WS_POPUP, screenX, screenY, this->windowWidth, this->windowHeight, NULL, NULL, this->m_hinstance, NULL);

	ShowWindow(this->m_hwnd, SW_SHOW);
	screenWidth = this->windowWidth;
	screenHeight = this->windowHeight;

	return true;
}

bool DXEngine::ShutdownWindow()
{
	DestroyWindow(this->m_hwnd);
	m_hwnd = 0;

	return true;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_QUIT:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return ApplicationHandle->MessageHandler(hwnd, message, wParam, lParam);
}
