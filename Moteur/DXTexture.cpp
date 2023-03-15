#include "DXTexture.h"

void DXTexture::Texture()
{
	this->Texture_1 = 0;
	this->Texture_2 = 0;
}

bool DXTexture::CreateTextures(LPDIRECT3DDEVICE9 devcon)
{
	HRESULT TextureCreated = D3DXCreateTextureFromFile(devcon, L"the_rock.jpg", &this->Texture_1);
	TextureCreated = D3DXCreateTextureFromFile(devcon, L"gt3.png", &this->Texture_2);

	return true;
}
