#pragma once
class Shader : public Component
{
public:
	Shader();
	~Shader();

	void Init(LPDIRECT3DDEVICE9 device, LPSTR path);
	void CreateShader(LPDIRECT3DDEVICE9 device);

	LPD3DXEFFECT shaderEffect;
	LPD3DXBUFFER errorBuffer;
};

