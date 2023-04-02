#pragma once

using namespace DirectX;
class Camera : public GameObject
{
public:

	void Init(IDirect3DDevice9* device) {
		
	}
	Camera();
	void SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ);

private:
	XMMATRIX projectionMatrix;
};

