#pragma once

class AABB:public Collider
{
public:
    AABB();
	AABB(D3DXVECTOR3* _pos);
    bool AABBvsAABB(AABB* box1, AABB* box2);
	static AABB* Get();


	float MaxX() const;
	float MinX() const;
	float MaxY() const;
	float MinY() const;
	float MaxZ() const;
	float MinZ() const;

    D3DXVECTOR3 m_min;
    D3DXVECTOR3 m_max;
};

