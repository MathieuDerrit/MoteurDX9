#include "moteur.h"

Button::Button() {
	buttonFont = nullptr;
}

Button::~Button() {
	if (buttonFont)
		buttonFont->Release();
}

void Button::Init(LPDIRECT3DDEVICE9 d3ddev)
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
		&buttonFont));

	//D3DXIMAGE_INFO info;
	//HR(D3DXGetImageInfoFromFile(boxFilepath, &info))

	//	if (size.x <= 0 || size.y <= 0)
	//	{
	//		drawBox = false;
	//	}

	//HR(D3DXCreateTextureFromFileEx(d3ddev,
	//	boxFilepath,
	//	size.x,
	//	size.y,
	//	info.MipLevels,
	//	0,
	//	info.Format,
	//	D3DPOOL_DEFAULT,
	//	D3DX_DEFAULT,
	//	D3DX_DEFAULT,
	//	0xFF000000,
	//	&info,
	//	NULL,
	//	&_texture))

	//HR(D3DXCreateSprite(d3ddev, &_sprite));
	SetRect(&buttonRect, 0, 0, 300, 300);
}

void Button::Update()
{
	Draw();

	if (isMouseOn() && !isDisabled) {
		if (Input::IsPressed(LMB))
			OnClick();
		else
			OnHover();
	}
}

void Button::Draw()
{
	_rectOrigin = position;
	_rectSize = position + size;

	auto result = SetRect(&buttonRect, _rectOrigin.x, _rectOrigin.y, _rectSize.x, _rectSize.y);

	//if (drawBox)
	//{
	//	HR(_sprite->Begin(D3DXSPRITE_ALPHABLEND));
	//	auto spritePostion = D3DXVECTOR3(_rectOrigin.x, _rectOrigin.y, 0);
	//	HR(_sprite->Draw(_texture, NULL, NULL, &spritePostion, boxColor))
	//	HR(_sprite->End())
	//}

	if (buttonFont)
		buttonFont->DrawTextA(NULL, message.c_str(), message.length(), &buttonRect, buttonFormat, textColor);
}

void Button::OnClick() {
	if (onClick != nullptr && Input::IsPressed(LMB)) {
		onClick();
	}
}



void Button::OnHover()
{
	//hover color
}

bool Button::UpdateMousepos()
{
	if (GetCursorPos(&mousePos)) {
		if (ScreenToClient(window, &mousePos)) {
			return true;
		}
	}
	return false;
}

bool Button::isMouseOn()
{
	return false;
}
