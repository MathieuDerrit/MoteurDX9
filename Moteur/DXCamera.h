#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class DXCamera
{
public:
	DXCamera();

	bool Initialize(LPDIRECT3DDEVICE9, int, int);

	D3DXMATRIX getViewMatrix();
	D3DXMATRIX getProjectionMatrix();

	void UpdateCam();

	float camX, camY, camZ;

private:
	D3DXMATRIX worldMatrix;
	D3DXMATRIX viewMatrix;
	D3DXMATRIX projectionMatrix;

	D3DXVECTOR3 vCam, vLook, vUp;
};