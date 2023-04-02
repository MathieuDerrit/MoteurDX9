#pragma once

class Transform
{
public:
    Transform();
    ~Transform();

    void setPosition(D3DXVECTOR3 position);

    void rotate(float yaw, float pitch, float roll);

    void rotate(D3DXMATRIX rotation);

    void setScale(D3DXVECTOR3 scale);

    void updateMatrix();

    float goYaw = 0.0f;
    float goPitch = 0.0f;
    float goRoll = 0.0f;

    D3DXVECTOR3 m_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    D3DXMATRIX m_mPos;

<<<<<<< HEAD
    //float yaw;
    //float pitch;
    //float roll;

    D3DXVECTOR3 m_dir;
    D3DXVECTOR3 m_up;
    D3DXVECTOR3 m_right;
    D3DXQUATERNION m_quat;
=======
    D3DXVECTOR3 m_dir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
    D3DXVECTOR3 m_up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    D3DXVECTOR3 m_right = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
    D3DXQUATERNION m_quat = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 0.0f);
>>>>>>> fix
    D3DXMATRIX m_mRot;

    D3DXVECTOR3 m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
    D3DXMATRIX m_mSca;

    D3DXMATRIX m_matrix;
};
