#include "moteur.h"

FieldText::FieldText() {
	textFont = nullptr;
}

FieldText::~FieldText()
{
	if (textFont)
		textFont->Release();
}

void FieldText::Init(LPDIRECT3DDEVICE9 d3ddev)
{
	HR(D3DXCreateFont(d3ddev, 
		fontHeight, 
		fontWidth, 
		fontWeight, 
		D3DX_DEFAULT, 
		fontItalic, 
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE, 
		font, 
		&textFont));

	SetRect(&textRect, 0, 0, 300, 300);

}

void FieldText::Update()
{
	Draw();
}

void FieldText::Draw()
{
	if (textFont)
		textFont->DrawTextA(NULL, text.c_str(), -1, &textRect, textFormat, D3DCOLOR_XRGB(0, 0, 0));

}


