#include "moteur.h"

DXGraphics::DXGraphics()
{
	this->DX = 0;
	this->Lighting = 0;
	this->Camera = 0;
	this->_devcon = 0;
	this->Models = 0;
	this->_hwnd = 0;
	this->windowWidth = 0;
	this->windowHeight = 0;
}

bool DXGraphics::InitializeGraphics(HWND hwnd, int w, int h)
{
	this->_hwnd = hwnd;
	this->windowWidth = w;
	this->windowHeight = h;

	this->DX = new DXManager();
	if (!DX)
		return false;

	this->_devcon = this->DX->Initialize(hwnd, w, h);

	if (!this->_devcon)
		return false;

	this->Models = new DXModels();
	if (!Models)
		return false;

	Models->InitializeModels(_devcon);

	this->Camera = new DXCamera();
	Camera->Initialize(_devcon, this->windowWidth, this->windowHeight);

	this->Lighting = new DXLights();
	if (!Lighting)
		return false;

	Lighting->InitLights(this->_devcon);

	return true;
}

void DXGraphics::Shutdown()
{
	delete this->Models;
	this->Models = 0;

	this->Lighting->CleanupLights();
	delete this->Lighting;
	this->Lighting = 0;

	delete this->Camera;
	this->Camera = 0;

	this->DX->Shutdown();
	delete DX;
	DX = 0;
}

bool DXGraphics::Render()
{
	static float index = 0.0f; index += 0.005f;
	DX->BeginScene();
	_devcon->SetFVF(CUSTOMFVF);

	//Update Camera
	Camera->UpdateCam();
	this->viewMatrix = Camera->getViewMatrix();
	this->projectionMatrix = Camera->getProjectionMatrix();
	_devcon->SetTransform(D3DTS_VIEW, &this->viewMatrix);
	_devcon->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	//Terrain
	_devcon->SetFVF(TEXTUREFVF);
	_devcon->SetStreamSource(0, Models->terrainBuffer, 0, sizeof(DXTexture::TEXTUREVERTEX));
	_devcon->SetTexture(0, Models->m_Textures->Texture_1);
	_devcon->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	_devcon->SetTexture(0, Models->m_Textures->Texture_2);

	//Rotate Cube -> DOIT UTILISER LE TRANSFORM
	D3DXMATRIX matRotate;
	D3DXMatrixRotationY(&matRotate, index);
	_devcon->SetTransform(D3DTS_WORLD, &matRotate);

	_devcon->SetStreamSource(0, Models->vBuffer, 0, sizeof(DXTexture::TEXTUREVERTEX));
	_devcon->SetIndices(Models->iBuffer);
	_devcon->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, 24, 0, 12);

	//Reset
	D3DXMatrixRotationY(&matRotate, 0);
	_devcon->SetTransform(D3DTS_WORLD, &matRotate);
	_devcon->SetTexture(0, NULL);
	_devcon->SetFVF(CUSTOMFVF);


	DX->EndScene();
	return true;
}
