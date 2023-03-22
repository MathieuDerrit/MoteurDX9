#include "framework.h"

Mesh::Mesh()
{
    m_mesh = nullptr;
}

Mesh::~Mesh()
{
    if (m_mesh)
    {
        m_mesh->Release();
    }
}

void Mesh::Init(IDirect3DDevice9* device, EMesh mesh, string customPath)
{
    switch (mesh) {
    case Box:
        D3DXCreateBox(device, 1.0f, 1.0f, 1.0f, &m_mesh, 0);
        break;
    case Cylinder:
        D3DXCreateCylinder(device, 1.0f, 1.0f, 1.0f, 10, 10, &m_mesh, 0);
        break;
    case Polygon_:
        D3DXCreatePolygon(device, 1.0f, 1, &m_mesh, 0);
        break;
    case Sphere:
        D3DXCreateSphere(device, 1.0f, 10, 10, &m_mesh, 0);
        break;
    case Teapot:
        D3DXCreateTeapot(device, &m_mesh, 0);
        break;
    case Text:
        D3DXCreateText(device, HDC(), L"Text", 0.1f, 0.1f, &m_mesh, 0, 0);
        break;
    case Torus:
        D3DXCreateTorus(device, 1.0f, 3.0f, 10, 10, &m_mesh, 0);
        break;   
    case Custom: {
        //Conversion du string en LPCWSTR
        std::wstring pathTemp = std::wstring(customPath.begin(), customPath.end());
        LPCWSTR path = pathTemp.c_str();

        //Load mesh
        LPD3DXBUFFER bufShipMaterial;

        D3DXLoadMeshFromX(path,    // load this file
            D3DXMESH_SYSTEMMEM,    // load the mesh into system memory
            device,    // the Direct3D Device
            NULL,    // we aren't using adjacency
            &bufShipMaterial,    // put the materials here
            NULL,    // we aren't using effect instances
            NULL,    // the number of materials in this model
            &m_mesh);    // put the mesh here
        
        //device->GetTransform(D3DTS_WORLD, &(m_gameObject->m_transform.m_matrix));
        break;
    }
    default:
        //D3DXCreateBox(device, 2.0f, 2.0f, 2.0f, &m_mesh, 0);
        break;
    }
}

void Mesh::Update(IDirect3DDevice9* device)
{
    meshTransform = m_gameObject->m_transform;
    device->SetTransform(D3DTS_WORLD, &(meshTransform.m_matrix));
}

bool Mesh::draw()
{
    m_mesh->DrawSubset(0);
    return true;
}