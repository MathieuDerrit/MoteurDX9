#pragma once


class Collider : public Component
{
public:
    Collider();
    Collider(D3DXVECTOR3 pos, float radius);
    virtual ~Collider();
    void SetPositionCenter(D3DXVECTOR3 posCenter);
    void SetRadius(float xradius);

    bool CollidesWith(Collider* other);
    D3DXVECTOR3 GetPositionCenter();
    float GetRadius();
    Collider* getCollideWith();

    Collider* collidewith;

protected:
    D3DXVECTOR3 m_positionCenter;
    float m_radius;
};