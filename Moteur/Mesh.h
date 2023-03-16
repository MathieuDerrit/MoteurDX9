#ifndef __meshH__
#define __meshH__

#include <d3dx9.h>
#include <string>

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

class Mesh
{
public:
	Mesh(IDirect3DDevice9* device, EMesh mesh);
	~Mesh();

	bool draw();
private:
	ID3DXMesh* m_mesh;
};
#endif