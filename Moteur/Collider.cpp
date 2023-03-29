#include "moteur.h"

Collider::Collider()
{
}

bool Collider::IsCollidingWith(Collider* other)
{
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

Collider::~Collider()
{
}




//Collider::Collider(float x, float y, float z, float halfWidth, float halfHeight, float halfDepth) :
//    m_position(x, y, z), m_halfSize(halfWidth, halfHeight, halfDepth)
//{
//}
//
//void Collider::SetPosition(float x, float y, float z)
//{
//    m_position = D3DXVECTOR3(x, y, z);
//}
//
//void Collider::SetHalfSize(float halfWidth, float halfHeight, float halfDepth)
//{
//    m_halfSize = D3DXVECTOR3(halfWidth, halfHeight, halfDepth);
//}
//
//bool Collider::IsCollidingWith(Collider* other) 
//{
//    printf("Collide");
//    // Calculate the minimum and maximum points of each AABB
//    D3DXVECTOR3 minA = m_position - m_halfSize;
//    D3DXVECTOR3 maxA = m_position + m_halfSize;
//    D3DXVECTOR3 minB = other->m_position - other->m_halfSize;
//    D3DXVECTOR3 maxB = other->m_position + other->m_halfSize;
//
//    // Check if there is any overlap in the X, Y, and Z axes
//    if (maxA.x < minB.x || minA.x > maxB.x) {
//        return false;
//    }
//    if (maxA.y < minB.y || minA.y > maxB.y) {
//        return false;
//    }
//    if (maxA.z < minB.z || minA.z > maxB.z) {
//        return false;
//    }
//
//    // If there is overlap in all three axes, there is a collision
//    return true;
//}
