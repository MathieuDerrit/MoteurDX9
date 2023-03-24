#pragma once
class Target : public GameObject
{
public:
	Target();
	~Target();

	void Init(IDirect3DDevice9* device) {
		GameObject::AddComponent<Mesh>();
		m_mesh = GameObject::GetComponent<Mesh>();
		m_mesh->Init(device, Custom, "balloon.x");

	}

private:
	Mesh* m_mesh;
};

