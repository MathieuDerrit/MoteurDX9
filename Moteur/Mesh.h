#pragma once

typedef enum
{
	Box,
	Cylinder,
	Polygon_,
	Sphere,
	Teapot,
	Text,
	Torus,
	Custom
}EMesh;

class Mesh : public Component
{
public:
	Mesh();
	~Mesh();

	void Init(IDirect3DDevice9* device, EMesh mesh, string customPath = "", string texturePath = "");
	void Update(IDirect3DDevice9* device);
	bool draw(IDirect3DDevice9* device = NULL);

	Transform meshTransform;
	ID3DXMesh* m_mesh;

	DWORD m_numMaterials = 0;
	LPDIRECT3DTEXTURE9* m_texture = new LPDIRECT3DTEXTURE9[m_numMaterials];
	D3DMATERIAL9* m_material = new D3DMATERIAL9[m_numMaterials];
};
