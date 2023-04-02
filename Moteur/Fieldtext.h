#pragma once
class FieldText : public Component
{
public:
	FieldText();
	~FieldText();

	void Init(LPDIRECT3DDEVICE9 d3ddev);
	void Update();
	void Draw();

	INT fontHeight = 25;
	UINT fontWidth = 0;
	UINT fontWeight = FW_NORMAL;
	BOOL fontItalic = false;
	LPCWSTR font = L"Arial";

	string text;
	DWORD textFormat = DT_CENTER | DT_VCENTER;

	LPCWSTR boxFilepath = L"Assets\\the_rock.jpg";

	D3DXVECTOR2 position = { 0,0 };
	D3DXVECTOR2 size = { 200, 50 };

	D3DCOLOR borderColor = D3DCOLOR_ARGB(255, 255, 166, 0);
	D3DCOLOR boxColor = D3DCOLOR_ARGB(255, 0, 255, 255);
	D3DCOLOR textColor = D3DCOLOR_ARGB(255, 255, 0, 255);

	FLOAT borderThickness = 5;

	bool drawBox = false;
	bool drawBorder = false;

private:

	RECT textRect;
	ID3DXFont* textFont = nullptr;

	LPDIRECT3DDEVICE9 d3ddev;
};

