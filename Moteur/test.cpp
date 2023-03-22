#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "AABB.h"

// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Cube dimensions
const float CUBE_WIDTH = 2.0f;
const float CUBE_HEIGHT = 2.0f;
const float CUBE_DEPTH = 2.0f;

D3DXVECTOR3 min1(-2.0f, 0.0f, -6.0f);
D3DXVECTOR3 max1(2.0f, 0.0f, 6.0f);

D3DXVECTOR3 min2(-1.0f, 0.0f, -3.0f);
D3DXVECTOR3 max2(1.0f, 0.0f, 3.0f);

// Cube positions
AABB cube1Pos(min1,max1);
AABB cube2Pos(min2, max2);

// Cube AABBs
D3DXVECTOR3 cube1Min(cube1Pos.m_min.x - CUBE_WIDTH / 2.0f, cube1Pos.m_min.y - CUBE_HEIGHT / 2.0f, cube1Pos.m_min.z - CUBE_DEPTH / 2.0f);
D3DXVECTOR3 cube1Max(cube1Pos.m_max.x + CUBE_WIDTH / 2.0f, cube1Pos.m_max.y + CUBE_HEIGHT / 2.0f, cube1Pos.m_max.z + CUBE_DEPTH / 2.0f);

D3DXVECTOR3 cube2Min(cube2Pos.m_min.x - CUBE_WIDTH / 2.0f, cube2Pos.m_min.y - CUBE_HEIGHT / 2.0f, cube2Pos.m_min.z - CUBE_DEPTH / 2.0f);
D3DXVECTOR3 cube2Max(cube2Pos.m_max.x + CUBE_WIDTH / 2.0f, cube2Pos.m_max.y + CUBE_HEIGHT / 2.0f, cube2Pos.m_max.z + CUBE_DEPTH / 2.0f);

// DirectX 9 objects
LPDIRECT3D9 d3d9 = NULL;
LPDIRECT3DDEVICE9 d3dDevice = NULL;
LPD3DXMESH cubeMesh = NULL;

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
bool InitDirect3D(HWND hWnd);
bool LoadMesh(LPCSTR filename, LPD3DXMESH* mesh);
void DrawCube(const D3DXVECTOR3& position, const D3DXVECTOR3& color);
void Update(float deltaTime);
void Render();
void Cleanup();

int WINAPI WinMainTest(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"DirectX Window Class";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    // Create the window
    HWND hWnd = CreateWindowEx(
        0,                              // Optional window styles
        L"DirectX Window Class",                     // Window class
        L"DirectX Window",               // Window title
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Window position
        WINDOW_WIDTH, WINDOW_HEIGHT,    // Window size
        NULL,                           // Parent window
        NULL,                           // Menu
        hInstance,                      // Instance handle
        NULL                            // Additional application data
    );

    if (hWnd == NULL) return 0;

    // Initialize Direct3D
    InitDirect3D(hWnd);



}

bool InitDirect3D(HWND hWnd)
{
    d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

    D3DPRESENT_PARAMETERS d3dpp;

    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = hWnd;
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dpp.BackBufferWidth = WINDOW_WIDTH;
    d3dpp.BackBufferHeight = WINDOW_HEIGHT;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    d3d9->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
        &d3dpp,
        &d3dDevice);


    
}

bool LoadMesh(LPCSTR filename, LPD3DXMESH* mesh)
{
    return false;
}

void DrawCube(const D3DXVECTOR3& position, const D3DXVECTOR3& color)
{


}

void Update(float deltaTime)
{


}

void Render()
{
    d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
    d3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    d3dDevice->BeginScene();



}

void Cleanup()
{
    d3d9->Release();
    d3dDevice->Release();

}
