#include"moteur.h"

AABB::AABB(float x, float y, float z, float halfWidth, float halfHeight, float halfDepth): 
	m_position(x, y, z), m_halfSize(halfWidth, halfHeight, halfDepth)
{
}

void AABB::SetPosition(float x, float y, float z)
{
	m_position = D3DXVECTOR3(x, y, z);
}

void AABB::SetHalfSize(float halfWidth, float halfHeight, float halfDepth)
{
	m_halfSize = D3DXVECTOR3(halfWidth, halfHeight, halfDepth);
}

bool AABB::IsCollidingWith(const AABB& other) const
{
    // Calculate the minimum and maximum points of each AABB
    D3DXVECTOR3 minA = m_position - m_halfSize;
    D3DXVECTOR3 maxA = m_position + m_halfSize;
    D3DXVECTOR3 minB = other.m_position - other.m_halfSize;
    D3DXVECTOR3 maxB = other.m_position + other.m_halfSize;

    // Check if there is any overlap in the X, Y, and Z axes
    if (maxA.x < minB.x || minA.x > maxB.x) {
        return false;
    }
    if (maxA.y < minB.y || minA.y > maxB.y) {
        return false;
    }
    if (maxA.z < minB.z || minA.z > maxB.z) {
        return false;
    }

    // If there is overlap in all three axes, there is a collision
    return true;
}
