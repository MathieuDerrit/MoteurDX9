#pragma once

class DXModels
{
public:
	DXModels();
	void InitializeModels(LPDIRECT3DDEVICE9 devcon);

	LPDIRECT3DVERTEXBUFFER9		vBuffer, terrainBuffer, pyramidBuffer;
	LPDIRECT3DINDEXBUFFER9		iBuffer, pyramidIndexBuffer;

	DXTexture* m_Textures;

	struct CUSTOMVERTEX
	{
		float x, y, z;
		D3DVECTOR NORMAL;
	};
};

const static DXTexture::TEXTUREVERTEX terrainVertices[] =
{
	{-20.f, -10.f, -20.f, D3DCOLOR_XRGB(255, 255, 255), 0.f, 0.f, },
	{20.f, -10.f, -20.f, D3DCOLOR_XRGB(255, 255, 255), 0.f, 1.f, },
	{-20.f, -10.f, 20.f, D3DCOLOR_XRGB(255, 255, 255), 1.f, 0.f, },
	{20.f, -10.f, 20.f, D3DCOLOR_XRGB(255, 255, 255), 1.f, 1.f, },
};

const static DXTexture::TEXTUREVERTEX vertices[] =
{
{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0.0f, },    // side 1
{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 1.0f, },
{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 1.0f, },

{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0.0f, },    // side 2
{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 1.0f, },
{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 1.0f, },

{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },    // side 3
{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },

{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 1.0f, },    // side 4
{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },

{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0.0f, },    // side 5
{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 1.0f, },
{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 1.0f, },

{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0.0f, },    // side 6
{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0.0f, },
{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 1.0f, },
{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 1.0f, },
};

const static DXModels::CUSTOMVERTEX pyramidVertexBuffer[] =
{
	{-12.f, -3.f, -12.f, 0.f, 0.f, 0.f, },
	{-12.f, -3.f, -5.f, 1.f, 0.f, 0.f, },
	{-5.f, -3.f, -12.f, -1.f, 0.f, 0.f, },
	{-5.f, -3.f, -5.f, 0.f, 0.f, 0.f, },

	{-8.5f, 0.f, -8.5f, 0.f, 1.f, 0.f, }
};
