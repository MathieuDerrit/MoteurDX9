#pragma once
class Raycast
{
public:
	void Init(D3DXVECTOR3 origin, D3DXVECTOR3 direction, float distance);
	void DrawLine(IDirect3DDevice9* device, Camera CameraView);
	void CreateRaycast(LPD3DXBASEMESH mesh, D3DXVECTOR3 origin, D3DXVECTOR3 direction, BOOL* isCollide);
	void UnDrawLine();

private:
	ID3DXLine* m_line = nullptr;
	D3DXMATRIX m_tempFinal;
	D3DXVECTOR3 m_points[2];
	D3DCOLOR m_color = D3DCOLOR_RGBA(255, 0, 0, 255);
};

