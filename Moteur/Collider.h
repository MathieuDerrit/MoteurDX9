#pragma once


class Collider : public Component
{
public:
	Collider();
	~Collider();

	void Init();
	void Update();

	AABB aabb;
	Transform colliderTransform;

	bool IsColliding();

};