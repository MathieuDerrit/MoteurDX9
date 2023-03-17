#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform
{
public:
    Transform();
    ~Transform();

    void setPosition(D3DXVECTOR3 position);

    void rotate(float yaw, float pitch, float roll);

    void setScale(D3DXVECTOR3 scale);

    void updateMatrix();

    D3DXVECTOR3 m_position;
    D3DXMATRIX m_mPos;

    float yaw = 0;
    float pitch = 0;
    float roll = 0;

    D3DXVECTOR3 m_dir;
    D3DXVECTOR3 m_up;
    D3DXVECTOR3 m_right;
    D3DXQUATERNION m_quat;
    D3DXMATRIX m_mRot;

    D3DXVECTOR3 m_scale;
    D3DXMATRIX m_mSca;

    D3DXMATRIX m_matrix;
};

#endif