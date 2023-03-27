#pragma once


class Collider : public Component
{
public:
    Collider() {}

    bool IsCollidingWith(Collider* other) {
        // Assume that this collider is a box collider
        // Check if other is also a box collider
        BoxCollider* otherBox = dynamic_cast<BoxCollider*>(other);
        if (otherBox == nullptr) {
            // If other collider is not a box collider, it's not colliding
            return false;
        }

        // Check if the two boxes are overlapping in each axis
        bool xOverlap = (m_min.x <= otherBox->m_max.x) && (otherBox->m_min.x <= m_max.x);
        bool yOverlap = (m_min.y <= otherBox->m_max.y) && (otherBox->m_min.y <= m_max.y);
        bool zOverlap = (m_min.z <= otherBox->m_max.z) && (otherBox->m_min.z <= m_max.z);

        // If they overlap in every axis, then they are colliding
        return xOverlap && yOverlap && zOverlap;
    }

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














//public:
//    Collider();
//    ~Collider();
//    Collider(float x, float y, float z, float halfWidth, float halfHeight, float halfDepth);
//
//    D3DXVECTOR3 GetPosition() { return m_position; }
//    void SetPosition(float x, float y, float z);
//
//    D3DXVECTOR3 GetHalfSize() { return m_halfSize; }
//    void SetHalfSize(float halfWidth, float halfHeight, float halfDepth);
//
//    bool IsCollidingWith(Collider* other);
//private:
//    D3DXVECTOR3 m_position;
//    D3DXVECTOR3 m_halfSize;
//
//};