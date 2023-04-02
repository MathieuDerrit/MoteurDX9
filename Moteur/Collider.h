#pragma once


class Collider : public Component
{
public:
    Collider();
    Collider(D3DXVECTOR3* pos);

    D3DXVECTOR3 GetPosition(D3DXVECTOR3 pos);

    D3DXVECTOR3 m_pos;
};