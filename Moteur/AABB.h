#pragma once

class AABB :public Component
{
public:
    AABB();

    bool AABBvsAABB(AABB* box1, AABB* box2);

    D3DXVECTOR3 m_min;
    D3DXVECTOR3 m_max;
};

