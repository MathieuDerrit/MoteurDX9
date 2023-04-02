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
	void Update();
	bool draw(IDirect3DDevice9* device);

	ID3DXMesh* getMesh() { return m_mesh; };
	void setMesh(ID3DXMesh* mesh) { m_mesh = mesh; };

private:
	Transform meshTransform;
	ID3DXMesh* m_mesh;

	DWORD m_numMaterials = 0;
	LPDIRECT3DTEXTURE9* m_texture = new LPDIRECT3DTEXTURE9[m_numMaterials];
	D3DMATERIAL9* m_material = new D3DMATERIAL9[m_numMaterials];
};
