#pragma once
#include <d3dx9.h>

class AABB
{
public:
	AABB() : 
		m_min(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),
		m_max(D3DXVECTOR3(0.0f, 0.0f, 0.0f)) {}

	AABB(D3DXVECTOR3 min, D3DXVECTOR3 max) : 
		m_min(min), 
		m_max(max) {}

	D3DXVECTOR3 GetMin() const { return m_min; }
	D3DXVECTOR3 GetMax() const { return m_max; }

	bool Intersects(const AABB& other) const
	{
		if (m_min.x > other.m_max.x || m_max.x < other.m_min.x) return false; // Check x-axis overlap
		if (m_min.y > other.m_max.y || m_max.y < other.m_min.y) return false; // Check y-axis overlap
		if (m_min.z > other.m_max.z || m_max.z < other.m_min.z) return false; // Check z-axis overlap

		return true; // Boxes overlap
	}

	D3DXVECTOR3 m_min;
	D3DXVECTOR3 m_max;
};