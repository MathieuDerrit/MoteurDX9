#pragma once
#include <d3d9.h>
#include <d3dx9.h>


class DXTexture
{
public:
	void Texture();

	bool CreateTextures(LPDIRECT3DDEVICE9 devcon);

	LPDIRECT3DTEXTURE9 Texture_1, Texture_2;

	struct TEXTUREVERTEX
	{
		FLOAT x, y, z;
		DWORD color;
		FLOAT tx, ty;
	};


};

