#pragma once
class Button : public Component
{
public:
	Button();
	~Button();
	function<void()> onClick = nullptr;


	void Init(LPDIRECT3DDEVICE9 device);
	void Update();
	bool ClickAction(string action);
	bool isClick();
	void Draw();
	void OnHover();
	bool UpdateMousepos();
	bool isMouseOn();

	INT fontHeight = 25;
	UINT fontWidth = 0;
	UINT fontWeight = FW_NORMAL;
	BOOL fontItalic = false;
	LPCWSTR font = L"Arial";
	string message = "Button test";
	DWORD buttonFormat = DT_CENTER | DT_VCENTER;
	POINT mousePos;

	Engine* eng;

	LPDIRECT3DDEVICE9 d3ddev;
	HWND window;

	LPDIRECT3DTEXTURE9 _texture;
	LPD3DXSPRITE _sprite;
	RECT buttonRect;
	ID3DXFont* buttonFont = nullptr;

	D3DCOLOR borderColor = D3DCOLOR_ARGB(255, 255, 166, 0);
	D3DCOLOR boxColor = D3DCOLOR_ARGB(255, 0, 255, 255);
	D3DCOLOR textColor = D3DCOLOR_ARGB(255, 255, 0, 255);

	D3DXVECTOR2 position = D3DXVECTOR2(0, 0);
	D3DXVECTOR2 size = D3DXVECTOR2(200, 100);

	D3DXVECTOR2 _rectOrigin;
	D3DXVECTOR2 _rectSize;

	LPCWSTR boxFilepath = L"Assets\\gt3.png";

	bool drawBox = true;
	bool drawBorder = true;
	bool isDisabled = false;
};