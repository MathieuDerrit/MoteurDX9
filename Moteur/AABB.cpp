#include "moteur.h"

AABB::AABB()
{

}

AABB::AABB(D3DXVECTOR3* _pos):
    Collider(_pos)
{
}

bool AABB::AABBvsAABB(AABB* box1, AABB* box2)
{
    //Check if Box1's max is greater than Box2's min and Box1's min is less than Box2's m
    return(box1->m_max.x > box2->m_min.x &&
        box1->m_min.x < box2->m_max.x &&
        box1->m_max.y > box2->m_min.y &&
        box1->m_min.y < box2->m_max.y &&
        box1->m_max.z > box2->m_min.z &&
        box1->m_min.z < box2->m_max.z);
    //If not, it will return false
}

AABB* AABB::Get()
{
    static AABB collisionDetect;
    return &collisionDetect;
}

float AABB::MaxX() const
{
    return m_max.x;
}

float AABB::MinX() const
{
    return m_min.x;
}

float AABB::MaxY() const
{
    return m_max.y ;
}

float AABB::MinY() const
{
    return m_min.y ;
}

float AABB::MaxZ() const
{
    return m_max.z;
}

float AABB::MinZ() const
{
    return m_min.z;
}


