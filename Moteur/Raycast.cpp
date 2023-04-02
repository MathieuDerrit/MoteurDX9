#include "moteur.h"

void Raycast::Init(D3DXVECTOR3 origin, D3DXVECTOR3 direction, float distance)
{
	m_points[0] = { origin };
	m_points[1] = { origin + (direction * distance) };
}

void Raycast::DrawLine(IDirect3DDevice9* device, Camera CameraView)
{
	D3DXMATRIX matProj = CameraView.GetProjectionMatrix();
	D3DXMATRIX matView = CameraView.GetViewMatrix();
	m_tempFinal = matView * matProj;

	D3DXCreateLine(device, &m_line);
	m_line->SetWidth(1.0f);
	m_line->Begin();
	m_line->DrawTransform(m_points, 2, &m_tempFinal, m_color);
	UnDrawLine();
	
}

void Raycast::UnDrawLine() {
	m_line->End();
	m_line->Release();
}

void Raycast::CreateRaycast(LPD3DXBASEMESH mesh, D3DXVECTOR3 origin, D3DXVECTOR3 direction, BOOL* isCollide)
{
	D3DXIntersect(mesh, &origin, &direction, isCollide, NULL, NULL, NULL, NULL, NULL, NULL);
}
