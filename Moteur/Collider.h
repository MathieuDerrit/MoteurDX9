#pragma once


class Collider : public Component
{
public:
	Collider();
	~Collider();

	void Init();
	void Update();


	bool IsColliding();

};