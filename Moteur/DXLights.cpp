#include "moteur.h"

DXLights::DXLights()
{
	this->devcon = 0;
}

void DXLights::InitLights(LPDIRECT3DDEVICE9 dev)
{
	this->devcon = dev;

	D3DMATERIAL9 material;

	ZeroMemory(&light1, sizeof(D3DLIGHT9));
	light1.Type = D3DLIGHT_DIRECTIONAL;
	light1.Diffuse = D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f);    //Set color
	light1.Direction = D3DXVECTOR3(1.0f, -.3f, -1.0f);
	ZeroMemory(&light1, sizeof(D3DLIGHT9));

	light2.Type = D3DLIGHT_POINT;
	light2.Diffuse = D3DXCOLOR(1.f, 0.f, .5f, 1.f);    //Set color
	light2.Position = D3DXVECTOR3(20.0f, 5.0f, -1.0f);
	light2.Range = 100.0f;
	light2.Attenuation0 = 0.0f;
	light2.Attenuation1 = 0.125f;
	light2.Attenuation2 = 0.0f;

	devcon->SetLight(0, &light1);
	devcon->LightEnable(0, TRUE);
	devcon->SetLight(1, &light1);
	devcon->LightEnable(1, FALSE);

	ZeroMemory(&material, sizeof(D3DMATERIAL9));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	material.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//Default drawing material for all object without textures
	devcon->SetMaterial(&material);
}

void DXLights::UpdateLights()
{
	static float pos = .5f; pos += .2f;

	this->light1.Position = D3DXVECTOR3(20.f, 5.f, -1.f);
	this->devcon->SetLight(1, &light1);
}

void DXLights::CleanupLights()
{
}
