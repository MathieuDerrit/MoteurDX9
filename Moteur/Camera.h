#pragma once

using namespace DirectX;
class Camera : public GameObject
{
public:

	void Init(IDirect3DDevice9* device) {

	}
	Camera();
	void SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ);

	//const XMMATRIX& GetViewMatrix() const;
	//const XMMATRIX& GetProjectionMatrix() const;
	D3DXMATRIX& GetViewMatrix();
	const D3DXMATRIX& GetProjectionMatrix() const;

	const XMVECTOR& GetPositionVector() const;
	const XMFLOAT3& GetPositionFloat3() const;
	const XMVECTOR& GetRotationVector() const;
	const XMFLOAT3& GetRotationFloat3() const;

	void SetPosition(const XMVECTOR& pos);
	void SetPosition(float x, float y, float z);
	void AdjustPosition(const XMVECTOR& pos);
	void AdjustPosition(float x, float y, float z);
	void SetRotation(const XMVECTOR& rot);
	void SetRotation(float x, float y, float z);
	void AdjustRotation(const XMVECTOR& rot);
	void AdjustRotation(float x, float y, float z);

	void UpdateViewMatrix();
private:
	XMVECTOR posVector;
	XMVECTOR rotVector;
	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMMATRIX viewMatrix;
	XMMATRIX projectionMatrix;

	D3DXMATRIX m_matProjection;
	D3DXMATRIX m_matView;

	//const XMVECTOR DEFAULT_FORWARD_VECTOR = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	//const XMVECTOR DEFAULT_UP_VECTOR = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	const D3DXVECTOR3 DEFAULT_FORWARD_VECTOR = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	const D3DXVECTOR3 DEFAULT_UP_VECTOR = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

};
