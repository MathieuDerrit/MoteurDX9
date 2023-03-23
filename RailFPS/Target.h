#pragma once
class Target : public GameObject
{
public:
	Target();
	~Target();

	void Init(IDirect3DDevice9* device) {
		GameObject::AddComponent<Mesh>();
		m_mesh = GameObject::GetComponent<Mesh>();
		//m_mesh->Init(device, Custom, "rail.x");
		m_mesh->Init(device, Box);
	}
	void Draw(IDirect3DDevice9* device) {
		m_mesh->Update();
		GameObject::GetComponent<Mesh>()->draw(device);
	}

private:
	//GameObject m_gameObject;
	Mesh* m_mesh;
};

