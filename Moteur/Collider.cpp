#include "moteur.h"

Collider::Collider()
{
}

Collider::Collider(D3DXVECTOR3* pos) :
	m_pos(*pos) {

}

D3DXVECTOR3 Collider::GetPosition(D3DXVECTOR3 pos) {
	return m_pos = pos;
}
