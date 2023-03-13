#include "Gameobject.h"

Gameobject::Gameobject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath)
{
    m_device = device;

    D3DXCreateTextureFromFile(m_device, texturePath, &m_texture);
    D3DXCreateTeapot(m_device, &m_mesh, NULL);
    // remplacez D3DXCreateTeapot par D3DXLoadMeshFromX pour charger un modèle 3D à partir d'un fichier

    m_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

Gameobject::~Gameobject()
{
    if (m_texture != NULL)
        m_texture->Release();

    if (m_mesh != NULL)
        m_mesh->Release();
}

void Gameobject::setPosition(float x, float y, float z)
{
    m_position = D3DXVECTOR3(x, y, z);
}

void Gameobject::setRotation(float x, float y, float z)
{
    m_rotation = D3DXVECTOR3(x, y, z);
}

void Gameobject::setScale(float x, float y, float z)
{
    m_scale = D3DXVECTOR3(x, y, z);
}



void Gameobject::drawCube(float width, float height, float depth, float r, float g, float b)
{
    // Crée une boîte avec les dimensions spécifiées
    LPD3DXMESH mesh;
    D3DXCreateBox(m_device, width, height, depth, &mesh, NULL);

    // configure la couleur du cube
    D3DMATERIAL9 material;
    ZeroMemory(&material, sizeof(D3DMATERIAL9));
    material.Diffuse.r = r;
    material.Diffuse.g = g;
    material.Diffuse.b = b;
    material.Diffuse.a = 1.0f;
    material.Ambient.r = r;
    material.Ambient.g = g;
    material.Ambient.b = b;

    // dessine le cube
    mesh->DrawSubset(0);

    // libère la mémoire utilisée par la boîte
    mesh->Release();
}


void Gameobject::render()
{
    // configure le monde transformation de la matrice
    // ... code de la fonction render existante ...

    // dessine l'objet principal
    m_mesh->DrawSubset(0);

    // dessine un cube rouge à la position (1, 0, 0)
    setPosition(1.0f, 0.0f, 0.0f);
    setRotation(0.0f, 0.0f, 0.0f);
    setScale(0.5f, 0.5f, 0.5f);
    drawCube(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
}