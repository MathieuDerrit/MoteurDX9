#pragma once


class Collider : public Component
{
public:
    Collider();
    ~Collider();

    bool IsCollidingWith(Collider* other);

    D3DXVECTOR3 m_min;
    D3DXVECTOR3 m_max;
};

class BoxCollider : public Collider {
public:
    BoxCollider() {}

    void SetBounds(D3DXVECTOR3 min, D3DXVECTOR3 max) {
        m_min = min;
        m_max = max;
    }
};