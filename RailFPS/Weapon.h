#pragma once
typedef enum
{
	Pistol,
	Riffle,
	Sniper
}EWeapon;

class Weapon : public GameObject
{
public:
	Weapon();
	~Weapon();

	void Init(IDirect3DDevice9* device, EWeapon weapon) {
		GameObject::AddComponent<Mesh>();
		m_mesh = GameObject::GetComponent<Mesh>();
		m_mesh->Init(device, Custom, filePath(weapon));

	}

	string filePath(EWeapon weapon) {
		string result = "";
		switch (weapon)
		{
		case Pistol:
			result = "blasterN.x";
			break;
		case Riffle:
			result = "targetA.x";
			break;
		case Sniper:
			result = "blasterC.x";
			break;
		default:
			result = "blasterA.x";
			break;
		}
		return result;
	}

private:
	Mesh* m_mesh;
};

