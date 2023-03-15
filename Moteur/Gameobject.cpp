#include "Gameobject.h"

Gameobject::Gameobject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath)
{
    m_device = device;

    D3DXCreateTextureFromFile(m_device, texturePath, &m_texture);
    D3DXCreateTeapot(m_device, &m_mesh, NULL);
    // remplacez D3DXCreateTeapot par D3DXLoadMeshFromX pour charger un mod�le 3D � partir d'un fichier
}

Gameobject::~Gameobject()
{
    if (m_texture != NULL)
        m_texture->Release();

    if (m_mesh != NULL)
        m_mesh->Release();
}

template<typename T>
T* Gameobject::AddComponent() 
{
    T* c = new T(this);
    m_components.push_back(c);
    return c;
}