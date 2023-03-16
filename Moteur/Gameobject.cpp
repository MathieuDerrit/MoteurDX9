#include "GameObject.h"

GameObject::GameObject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath)
{
    m_device = device;
}

GameObject::~GameObject()
{
    
}

template<typename T>
T* GameObject::AddComponent() 
{
    T* c = new T;
    c->SetGO(this);
    m_components.push_back(c);
    return c;
}