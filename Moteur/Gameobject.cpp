#include "GameObject.h"

GameObject::GameObject(LPDIRECT3DDEVICE9 device, const WCHAR* texturePath)
{
    m_device = device;
}

GameObject::~GameObject()
{

}