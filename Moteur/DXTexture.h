#pragma once


class DXTexture
{
public:
	DXTexture();

	bool CreateTextures(LPDIRECT3DDEVICE9 devcon);

	LPDIRECT3DTEXTURE9 Texture_1, Texture_2;

	struct TEXTUREVERTEX
	{
		FLOAT x, y, z;
		DWORD color;
		FLOAT tx, ty;
	};
};