#include "mesh.h"

Mesh::Mesh(IDirect3DDevice9* device, EMesh mesh)
{
    switch (mesh) {
    case Box:
        D3DXCreateBox(
            device,
            2.0f, // width
            2.0f, // height
            2.0f, // depth
            &m_mesh,
            0);
        break;
    case Cylinder:
        D3DXCreateCylinder(
            device,
            1.0f, // radius at negative z end
            1.0f, // radius at positive z end
            3.0f, // length of cylinder
            10,   // slices
            10,   // stacks
            &m_mesh,
            0);
        break;
    case Polygon_:
        D3DXCreatePolygon(
            device,
            1.0f,
            1,
            &m_mesh,
            0
        );
        break;
    case Sphere:
        D3DXCreateSphere(
            device,
            1.0f, // radius
            10,   // slices
            10,   // stacks
            &m_mesh,
            0);
        break;
    case Teapot:
        D3DXCreateTeapot(
            device,
            &m_mesh,
            0);
        break;
    case Text:
        D3DXCreateText(
            device,
            HDC(),
            L"Text",
            0.1f,
            0.1f,
            &m_mesh,
            0,
            0
        );
        break;
    case Torus:
        D3DXCreateTorus(
            device,
            1.0f, // inner radius
            3.0f, // outer radius
            10,   // sides
            10,   // rings
            &m_mesh,
            0);
        break;
    default:
        D3DXCreateBox(
            device,
            2.0f, // width
            2.0f, // height
            2.0f, // depth
            &m_mesh,
            0);
    }
}

Mesh::~Mesh()
{

}

bool Mesh::draw()
{
    m_mesh->DrawSubset(0);
	return true;
}