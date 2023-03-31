#include "moteur.h"

Collider::Collider()
{
}

Collider::Collider(D3DXVECTOR3 pos, float radius)
{
	m_positionCenter = pos; // a changer pour le centre du mesh
	m_radius = radius; // a changer pour la taille du mesh
}

Collider::~Collider()
{
    
}

void Collider::SetPositionCenter(D3DXVECTOR3 posCenter)
{
	m_positionCenter = posCenter;
}

void Collider::SetRadius(float xradius)
{
	m_radius = xradius;
}

bool Collider::CollidesWith(Collider* other)
{
    D3DXVECTOR3 otherPos = other->GetPositionCenter();
    float otherSize = other->GetRadius();
    float dx = m_positionCenter.x - otherPos.x;
    float dy = m_positionCenter.y - otherPos.y;
    float dz = m_positionCenter.z - otherPos.z;
    float distance = sqrt(dx * dx + dy * dy + dz * dz);
    if (distance < m_radius + otherSize)
    {
        collidewith = other;
        return true;
    }
    collidewith = NULL;
    return false;
}

D3DXVECTOR3 Collider::GetPositionCenter()
{
	return m_positionCenter;
}

float Collider::GetRadius()
{
	return m_radius;
}

Collider* Collider::getCollideWith()
{
	return collidewith;
}
