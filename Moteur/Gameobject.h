#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <d3d9.h>
#include <d3dx9.h>
#include "Transform.h"

class Gameobject
{
public:
    Gameobject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath);
    ~Gameobject();

    //Faire des component à ajouter (ex: mesh renderer, collider, etc...)

private:
    LPDIRECT3DDEVICE9 m_device;
    LPDIRECT3DTEXTURE9 m_texture;
    LPD3DXMESH m_mesh;
    Transform m_transform;
};

#endif // GAMEOBJECT_H