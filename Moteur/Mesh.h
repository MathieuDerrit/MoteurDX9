#ifndef __meshH__
#define __meshH__

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

	void Init(IDirect3DDevice9* device, EMesh mesh, string customPath = "");
	void Update(IDirect3DDevice9* device);
	bool draw();

	Transform meshTransform;
	ID3DXMesh* m_mesh;
};
#endif