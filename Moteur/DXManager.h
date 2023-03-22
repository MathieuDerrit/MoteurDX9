#pragma once


class DXManager
{
public:
	DXManager();

	LPDIRECT3DDEVICE9 Initialize(HWND hwnd, int w, int h);
	bool InitGraphics();
	void BeginScene();
	void EndScene();
	void Shutdown();

	float camX, camY, camZ;

	LPDIRECT3D9	d3d;
	LPDIRECT3DDEVICE9 d3ddev;

	HWND m_hwnd;
	int screenWidth, screenHeight;
};

