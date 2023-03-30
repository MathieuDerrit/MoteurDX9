#pragma once

class Engine
{
private:
	LPDIRECT3D9 d3d;
	LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;
	LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;

	KeyboardClass keyboard;
	MouseClass mouse;
	
public:
	Engine() {}

	void Init(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow);
	void initD3D(HWND* hWnd);
	void initInput();
	void init_light(void);


	void Update();
	void render_frame(void);

	//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

	void cleanD3D(void);
	vector<GameObject*> gameobjectlist;
	LPDIRECT3DDEVICE9 d3ddev;
	Camera* camera = NULL;
};