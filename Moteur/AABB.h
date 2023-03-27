#pragma once
#include <d3dx9.h>

class AABB
{
public:
    AABB(float x, float y, float z, float halfWidth, float halfHeight, float halfDepth);

    D3DXVECTOR3 GetPosition() const { return m_position; }
    void SetPosition(float x, float y, float z);
    D3DXVECTOR3 GetHalfSize() const { return m_halfSize; }
    void SetHalfSize(float halfWidth, float halfHeight, float halfDepth);

    bool IsCollidingWith(const AABB& other) const;
private:
    D3DXVECTOR3 m_position;
    D3DXVECTOR3 m_halfSize;
};