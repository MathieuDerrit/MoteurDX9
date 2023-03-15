#include "DXGraphics.h"

void DXGraphics::GraphicsEngine()
{
	this->DX = 0;
	//this->Lighting = 0;
	//this->Cam = 0;
	this->g_devcon = 0;
	//this->g_models = 0;
	this->g_hwnd = 0;
	this->windowWidth = 0;
	this->windowHeight = 0;
}

bool DXGraphics::InitializeGraphics(HWND, int, int)
{
	return false;
}

void DXGraphics::Shutdown()
{
}

bool DXGraphics::Render()
{
	return false;
}
