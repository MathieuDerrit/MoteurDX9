#include "GameObject.h"

GameObject::GameObject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath)
{
    m_device = device;

    D3DXCreateTextureFromFile(m_device, texturePath, &m_texture);
    D3DXCreateTeapot(m_device, &m_mesh, NULL);
    // remplacez D3DXCreateTeapot par D3DXLoadMeshFromX pour charger un modèle 3D à partir d'un fichier
}

GameObject::~GameObject()
{
    if (m_texture != NULL)
        m_texture->Release();

    if (m_mesh != NULL)
        m_mesh->Release();
}

template<typename T>
T* GameObject::AddComponent() 
{
    T* c = new T(this);
    m_components.push_back(c);
    return c;
}