#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <d3d9.h>
#include <d3dx9.h>
#include <memory>
#include <list>
#include <vector>
#include "Transform.h"
#include "Component.h"

using namespace std;

class GameObject
{
public:
    GameObject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath);
    ~GameObject();

    //Faire des component � ajouter (ex: mesh renderer, collider, etc...)
    template<typename T>
    T* AddComponent();
    template<typename T>
    T* GetComponent();
    template<typename T>
    list<T*> GetComponents();

    Transform m_transform;

    LPDIRECT3DDEVICE9 m_device;
    vector<Component*> m_components;
};

template<typename T>
T* GameObject::AddComponent()
{
    T* c = new T;
    c->SetGO(this);
    m_components.push_back(c);
    return c;
}

template<typename T>
T* GameObject::GetComponent()
{
    for (int i = 0; i < m_components.size(); i++)
    {
        if (dynamic_cast<T*>(m_components[i]) != nullptr)
        {
            return dynamic_cast<T*>(m_components[i]);
        }
    }
}

template <typename T>
list<T*> GameObject::GetComponents()
{
    std::list<T*> components;
    for (int i = 0; i < m_components.size(); i++)
    {
        if (dynamic_cast<T*>(m_components[i]) != nullptr)
        {
            components.pushBack(dynamic_cast<T*>(m_components[i]));
        }
    }
    return components;
}

#endif // GameObject_H