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
	Torus
}EMesh;

class Mesh : public Component
{
public:
	Mesh();
	~Mesh();

	void Init(IDirect3DDevice9* device, EMesh mesh);

	bool draw();
private:
	ID3DXMesh* m_mesh;
};
#endif