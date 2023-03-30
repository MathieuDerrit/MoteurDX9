#include "moteur.h"

Mesh::Mesh()
{
    m_mesh = nullptr;
}

Mesh::~Mesh()
{
    if (m_mesh)
        m_mesh->Release();
    if (m_material)
        delete m_material;
    if (m_texture)
        delete m_texture;

}

void Mesh::Init(IDirect3DDevice9* device, EMesh mesh, string customPath, string texturePath)
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
        wstring pathTemp = wstring(customPath.begin(), customPath.end());
        LPCWSTR path = pathTemp.c_str();

        //Load mesh
        LPD3DXBUFFER bufShipMaterial;

        D3DXLoadMeshFromX(path,    // load this file
            D3DXMESH_SYSTEMMEM,    // load the mesh into system memory
            device,    // the Direct3D Device
            NULL,    // we aren't using adjacency
            &bufShipMaterial,    // put the materials here
            NULL,    // we aren't using effect instances
            &m_numMaterials,    // the number of materials in this model
            &m_mesh);    // put the mesh here

        D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufShipMaterial->GetBufferPointer();
        m_material = new D3DMATERIAL9[m_numMaterials];
        m_texture = new LPDIRECT3DTEXTURE9[m_numMaterials];

        for (DWORD index = 0; index < m_numMaterials; index++)
        {
            m_material[index] = tempMaterials[index].MatD3D;
            m_material[index].Ambient = m_material[index].Diffuse;
            
            if (tempMaterials[index].pTextureFilename != NULL) 
            {
                texturePath = tempMaterials[index].pTextureFilename;
                // if there is a texture to load, load it 

                if (FAILED(D3DXCreateTextureFromFileA(device, texturePath.c_str(), &m_texture[index])))
                    m_texture[index] = NULL;    // if there is no texture, set the texture to NULL 
            }else
                m_texture[index] = NULL;
        }

        break;
    }
    default:
        //D3DXCreateBox(device, 2.0f, 2.0f, 2.0f, &m_mesh, 0);
        break;
    }

    
}

void Mesh::Update()
{
    meshTransform = m_gameObject->m_transform;
}

bool Mesh::draw(IDirect3DDevice9* device)
{
    device->SetTransform(D3DTS_WORLD, &(meshTransform.m_matrix));
    device->SetTexture(0, NULL);


    for (DWORD i = 0; i < m_numMaterials; i++)
    {
        device->SetMaterial(&m_material[i]);
        if (m_texture[i] != NULL)
            device->SetTexture(0, m_texture[i]);
        // Draw the mesh subset
        m_mesh->DrawSubset(i);
    }

    if (m_numMaterials == 0) {
        m_mesh->DrawSubset(0);
    }

    //m_mesh->DrawSubset(0);
    return true;
}