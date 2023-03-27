#pragma once
typedef enum
{
	Balloon,
	TargetA,
	TargetB
}ETarget;

class Target : public GameObject
{
public:
	Target();
	~Target();

	void Init(IDirect3DDevice9* device, ETarget target) {
		GameObject::AddComponent<Mesh>();
		m_mesh = GameObject::GetComponent<Mesh>();
		m_mesh->Init(device, Custom, filePath(target));

	}

	string filePath(ETarget target) {
		string result = "";
		switch (target)
		{
		case Balloon:
			result = "balloon.x";
			break;
		case TargetA:
			result = "targetA.x";
			break;
		case TargetB:
			result = "targetB.x";
			break;
		default:
			result = "balloon.x";
			break;
		}
		return result;
	}

private:
	Mesh* m_mesh;
};

