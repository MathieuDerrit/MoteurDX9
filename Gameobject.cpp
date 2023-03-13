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

void Gameobject::render()
{
    // configure le monde transformation de la matrice
    D3DXMATRIX matWorld;
    D3DXMatrixIdentity(&matWorld);
    D3DXMATRIX matScale;
    D3DXMatrixScaling(&matScale, m_scale.x, m_scale.y, m_scale.z);
    D3DXMATRIX matRotationX;
    D3DXMatrixRotationX(&matRotationX, m_rotation.x);
    D3DXMATRIX matRotationY;
    D3DXMatrixRotationY(&matRotationY, m_rotation.y);
    D3DXMATRIX matRotationZ;
    D3DXMatrixRotationZ(&matRotationZ, m_rotation.z);
    D3DXMATRIX matTranslation;
    D3DXMatrixTranslation(&matTranslation, m_position.x, m_position.y, m_position.z);
    matWorld = matScale * matRotationX * matRotationY * matRotationZ * matTranslation;
    m_device->SetTransform(D3DTS_WORLD, &matWorld);

    // configure les paramètres de rendu de texture
    m_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    m_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
    m_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
    //m_device->SetTexture(0, m_texture);

    // dessine l'objet
    m_mesh->DrawSubset(0);


}