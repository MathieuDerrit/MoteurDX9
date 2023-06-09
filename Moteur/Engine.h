#pragma once

class Engine
{
private:
	LPDIRECT3D9 d3d;
	LPDIRECT3DVERTEXBUFFER9 v_buffer;
	LPDIRECT3DINDEXBUFFER9 i_buffer;

	Camera* camera;

	KeyboardClass keyboard;
	MouseClass mouse;
	LPD3DXMESH mm;
	
public:
	Engine();

	void Init(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow);
	void initD3D(HWND* hWnd);
	void initShader();
	void init_light(void);


	void Update();
	void render_frame(void);

	//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

	void cleanD3D(void);
	vector<GameObject*> gameobjectlist;
	vector<Raycast*> raycastlist;
	LPDIRECT3DDEVICE9 d3ddev;
	Camera* camera = NULL;
	Input input;
};
