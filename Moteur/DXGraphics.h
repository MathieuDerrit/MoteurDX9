#pragma once
#include "DXEngine.h"
#include"DXModels.h"

//Tout ce qui est visuel, c'est ici ça gère
class DXGraphics
{
public:
	void GraphicsEngine();

	bool InitializeGraphics(HWND, int, int);
	void Shutdown();
	bool Render();

	DXEngine* DX;

private:
	D3DXMATRIX viewMatrix, projectionMatrix, worldMatrix;

	LPDIRECT3DDEVICE9 g_devcon;
	HWND g_hwnd;
	int windowWidth, windowHeight;

};

