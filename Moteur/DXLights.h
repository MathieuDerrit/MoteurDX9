#pragma once

class DXLights
{
public:
	DXLights();

	void InitLights(LPDIRECT3DDEVICE9 dev);
	void UpdateLights();
	void CleanupLights();

private:
	LPDIRECT3DDEVICE9 devcon;
	D3DLIGHT9 light1, light2;
};