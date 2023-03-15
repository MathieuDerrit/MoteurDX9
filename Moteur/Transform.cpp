#include "Transform.h"


Transform::Transform()
{
    m_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale)
{
    m_position = position;
    m_rotation = rotation;
    m_scale = scale;
}

Transform::~Transform()
{
}

D3DXVECTOR3 Transform::getPosition() const
{
    return m_position;
}

void Transform::setPosition(D3DXVECTOR3 position)
{
    m_position = position;
}

D3DXVECTOR3 Transform::getRotation() const
{
    return m_rotation;
}

void Transform::setRotation(D3DXVECTOR3 rotation)
{
    m_rotation = rotation;
}

D3DXVECTOR3 Transform::getScale() const
{
    return m_scale;
}

void Transform::setScale(D3DXVECTOR3 scale)
{
    m_scale = scale;
}

D3DXMATRIX Transform::getWorldMatrix() const
{
    D3DXMATRIX worldMatrix;
    D3DXMATRIX translationMatrix;
    D3DXMATRIX rotationMatrix;
    D3DXMATRIX scalingMatrix;

    D3DXMatrixTranslation(&translationMatrix, m_position.x, m_position.y, m_position.z);
    D3DXMatrixRotationYawPitchRoll(&rotationMatrix, m_rotation.y, m_rotation.x, m_rotation.z);
    D3DXMatrixScaling(&scalingMatrix, m_scale.x, m_scale.y, m_scale.z);

    worldMatrix = scalingMatrix * rotationMatrix * translationMatrix;

    return worldMatrix;
}
