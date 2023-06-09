#include "moteur.h"


Transform::Transform()
{
    D3DXQuaternionIdentity(&m_quat);
    D3DXMatrixIdentity(&m_mPos);
    D3DXMatrixIdentity(&m_mSca);
    D3DXMatrixIdentity(&m_mRot);

    m_dir.x = 0.0f;
    m_dir.y = 0.0f;
    m_dir.z = 1.0f;

    m_up.x = 0.0f;
    m_up.y = 1.0f;
    m_up.z = 0.0f;

    m_right.x = 1.0f;
    m_right.y = 0.0f;
    m_right.z = 0.0f;

    updateMatrix();
}

Transform::~Transform()
{
}


void Transform::setPosition(D3DXVECTOR3 position)
{
    m_position = position;
    D3DXMatrixTranslation(&m_mPos, m_position.x, m_position.y, m_position.z);
    updateMatrix();
}

void Transform::rotate(float yaw, float pitch, float roll)
{
    D3DXQUATERNION quat;
    D3DXQUATERNION quatRot;
<<<<<<< HEAD
=======

    goYaw = yaw;
    goPitch = pitch;
    goRoll = roll;

>>>>>>> fix
    D3DXQuaternionRotationAxis(&quat, &m_up, yaw);
    quatRot = quat;
    D3DXQuaternionRotationAxis(&quat, &m_right, pitch);
    quatRot *= quat;
    D3DXQuaternionRotationAxis(&quat, &m_dir, roll);
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
    m_scale = scale;
    D3DXMatrixScaling(&m_mSca, m_scale.x, m_scale.y, m_scale.z);
    updateMatrix();
}

void Transform::updateMatrix()
{
    D3DXMatrixTransformation(&m_matrix, NULL, NULL, &m_scale, NULL, &m_quat, &m_position);
    /*m_matrix *= m_mRot;
    m_matrix = m_mSca;
    m_matrix *= m_mPos;*/
}
