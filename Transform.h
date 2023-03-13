#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <d3dx9.h>
#include <d3d9.h>
#include <D3D9Types.h>

class Transform
{
public:
    Transform();
    Transform(D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale);
    ~Transform();

    D3DXVECTOR3 getPosition() const;
    void setPosition(D3DXVECTOR3 position);

    D3DXVECTOR3 getRotation() const;
    void setRotation(D3DXVECTOR3 rotation);

    D3DXVECTOR3 getScale() const;
    void setScale(D3DXVECTOR3 scale);

    D3DXMATRIX getWorldMatrix() const;

private:
    D3DXVECTOR3 m_position;
    D3DXVECTOR3 m_rotation;
    D3DXVECTOR3 m_scale;
};

#endif

