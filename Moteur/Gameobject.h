#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <d3d9.h>
#include <d3dx9.h>
#include <memory>
#include <list>
#include "Transform.h"
#include "Component.h"

using namespace std;

class Gameobject
{
public:
    Gameobject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath);
    ~Gameobject();

    //Faire des component à ajouter (ex: mesh renderer, collider, etc...)
    template<typename T>
    T* AddComponent();

private:
    LPDIRECT3DDEVICE9 m_device;
    LPDIRECT3DTEXTURE9 m_texture;
    LPD3DXMESH m_mesh;
    Transform m_transform;
    list<Component*> m_components;
};

#endif // GAMEOBJECT_H