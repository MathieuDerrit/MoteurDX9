#include "framework.h"


Transform::Transform()
{
    m_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_quat = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

Transform::~Transform()
{
}


void Transform::setPosition(D3DXVECTOR3 position)
{
    if (m_position != position)
    {
        m_position = position;
        D3DXMatrixTranslation(&m_mPos, m_position.x, m_position.y, m_position.z);
        updateMatrix();
    }
}

void Transform::rotate(float yaw, float pitch, float roll)
{
    if (pitch == m_quat.x && yaw == m_quat.y && roll == m_quat.z)
        return;
    D3DXQUATERNION quat;
    D3DXQUATERNION quatRot;
    D3DXQuaternionRotationAxis(&quat, &m_dir, roll);
    quatRot *= quat;
    D3DXQuaternionRotationAxis(&quat, &m_right, pitch);
    quatRot *= quat;
    D3DXQuaternionRotationAxis(&quat, &m_up, yaw);
    quatRot *= quat;

    m_quat *= quatRot;

    D3DXMatrixRotationQuaternion(&m_mRot, &m_quat);

    m_right.x = m_mRot._11;
    m_right.y = m_mRot._12;
    m_right.z = m_mRot._13;
    m_up.x = m_mRot._21;
    m_up.y = m_mRot._22;
    m_up.z = m_mRot._23;
    m_dir.x = m_mRot._31;
    m_dir.y = m_mRot._32;
    m_dir.z = m_mRot._33;

    updateMatrix();
}

void Transform::setScale(D3DXVECTOR3 scale)
{
    if (m_scale != scale) 
    {
        m_scale = scale;
        D3DXMatrixScaling(&m_mSca, m_scale.x, m_scale.y, m_scale.z);
        updateMatrix();
    }
}

void Transform::updateMatrix()
{
    m_matrix = m_mSca;
    m_matrix *= m_mRot;
    m_matrix *= m_mPos;
}
