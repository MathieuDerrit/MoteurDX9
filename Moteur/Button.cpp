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

	D3DXIMAGE_INFO info;
	HR(D3DXGetImageInfoFromFile(boxFilepath, &info))

		if (size.x <= 0 || size.y <= 0)
		{
			drawBox = false;
		}

	HR(D3DXCreateTextureFromFileEx(d3ddev,
		boxFilepath,
		size.x,
		size.y,
		info.MipLevels,
		0,
		info.Format,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0xFF000000,
		&info,
		NULL,
		&_texture))

	HR(D3DXCreateSprite(d3ddev, &_sprite));
	SetRect(&buttonRect, 0, 0, 300, 300);
}

void Button::Update()
{
	Draw();
	if (isMouseOn() && !isDisabled) {
		if (Input::IsPressed(LMB))
			isClick();
		else
			OnHover();
	}
}

bool Button::ClickAction(string action)
{
	Draw();
	mousePos.x = Input::GetMouseX();
	mousePos.y = Input::GetMouseY();

	ScreenToClient(window, &mousePos);

	if (Input::IsPressed(LMB))
	{
		if (mousePos.x > buttonRect.left && mousePos.x < buttonRect.right &&
			mousePos.y > buttonRect.top && mousePos.y < buttonRect.bottom)
		{
			if (action == "Play") {
				OutputDebugStringA("Play");
				HR(_sprite->End());
			}
			else if (action == "Quit")
			{
				OutputDebugStringA("Quit");
				exit(0);
			}
		}
		return false;
	}
}

void Button::Draw()
{
	_rectOrigin = position;
	_rectSize = position + size;

	auto result = SetRect(&buttonRect, _rectOrigin.x, _rectOrigin.y, _rectSize.x, _rectSize.y);

	if (drawBox)
	{
		HR(_sprite->Begin(D3DXSPRITE_ALPHABLEND));
		auto spritePostion = D3DXVECTOR3(_rectOrigin.x, _rectOrigin.y, 0);
		HR(_sprite->Draw(_texture, NULL, NULL, &spritePostion, boxColor))
		HR(_sprite->End())
	}

	if (buttonFont)
		buttonFont->DrawTextA(NULL, message.c_str(), message.length(), &buttonRect, buttonFormat, textColor);

	
}

bool Button::isClick() {
	if (onClick != nullptr && Input::IsPressed(LMB)) {
		onClick();
		return true;

	}
	return false;
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
	if (mousePos.x <= buttonRect.right && mousePos.x >= buttonRect.left)
	{
		if (mousePos.y <= buttonRect.bottom && mousePos.y >= buttonRect.top)
		{
			return true;
		}
	}
	return false;
}
