#pragma once
#include "DXManager.h"
#include "DXLights.h"
#include "DXModels.h"
#include "DXCamera.h"


//Tout ce qui est visuel, c'est ici ça gère
class DXGraphics
{
public:
	DXGraphics();

	bool InitializeGraphics(HWND, int, int);
	void Shutdown();
	bool Render();

	DXManager* DX;
	DXCamera* Camera;

private:
	DXLights* Lighting;
	DXModels* Models;

	D3DXMATRIX viewMatrix, projectionMatrix, worldMatrix;

	LPDIRECT3DDEVICE9 _devcon;
	HWND _hwnd;
	int windowWidth, windowHeight;

};