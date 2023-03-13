#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <d3d9.h>
#include <d3dx9.h>

class Gameobject
{
public:
    Gameobject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath);
    ~Gameobject();

    void setPosition(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);

    void render();

private:
    LPDIRECT3DDEVICE9 m_device;
    LPDIRECT3DTEXTURE9 m_texture;
    LPD3DXMESH m_mesh;

    D3DXVECTOR3 m_position;
    D3DXVECTOR3 m_rotation;
    D3DXVECTOR3 m_scale;
};

#endif // GAMEOBJECT_H