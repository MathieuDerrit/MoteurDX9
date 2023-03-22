#include "moteur.h"

DXCamera::DXCamera()
{
	this->camX = 0.f;
	this->camY = 8.f;
	this->camZ = 25.f;

	this->vCam = D3DXVECTOR3(this->camX, this->camY, this->camZ);
	this->vLook = D3DXVECTOR3(0.f, 0.f, 0.f);
	this->vUp = D3DXVECTOR3(0.f, 1.f, 0.f);
}

bool DXCamera::Initialize(LPDIRECT3DDEVICE9, int sWidth, int sHeight)
{
	//Projection matrix should stay the same for now
	D3DXMatrixPerspectiveFovLH(&this->projectionMatrix, D3DXToRadian(45), (FLOAT)sWidth / (FLOAT)sHeight, 1.0f, 100.f);

	return true;
}

D3DXMATRIX DXCamera::getViewMatrix()
{
	return this->viewMatrix;
}

D3DXMATRIX DXCamera::getProjectionMatrix()
{
	return this->projectionMatrix;
}

void DXCamera::UpdateCam()
{
	//Update view matrix
	this->vCam = D3DXVECTOR3(this->camX, this->camY, this->camZ);
	D3DXMatrixLookAtLH(&viewMatrix, &vCam, &vLook, &vUp);
}
