//#include <windows.h>
//#include <d3d9.h>
//#include <d3dx9.h>
//
//// Window dimensions
//const int WINDOW_WIDTH = 800;
//const int WINDOW_HEIGHT = 600;
//
//// Cube dimensions
//const float CUBE_WIDTH = 2.0f;
//const float CUBE_HEIGHT = 2.0f;
//const float CUBE_DEPTH = 2.0f;
//
//// Cube positions
//D3DXVECTOR3 cube1Pos(-2.0f, 0.0f, -6.0f);
//D3DXVECTOR3 cube2Pos(2.0f, 0.0f, -6.0f);
//
//// Cube AABBs
//D3DXVECTOR3 cube1Min(cube1Pos.x - CUBE_WIDTH / 2.0f, cube1Pos.y - CUBE_HEIGHT / 2.0f, cube1Pos.z - CUBE_DEPTH / 2.0f);
//D3DXVECTOR3 cube1Max(cube1Pos.x + CUBE_WIDTH / 2.0f, cube1Pos.y + CUBE_HEIGHT / 2.0f, cube1Pos.z + CUBE_DEPTH / 2.0f);
//D3DXVECTOR3 cube2Min(cube2Pos.x - CUBE_WIDTH / 2.0f, cube2Pos.y - CUBE_HEIGHT / 2.0f, cube2Pos.z - CUBE_DEPTH / 2.0f);
//D3DXVECTOR3 cube2Max(cube2Pos.x + CUBE_WIDTH / 2.0f, cube2Pos.y + CUBE_HEIGHT / 2.0f, cube2Pos.z + CUBE_DEPTH / 2.0f);
//
//// DirectX 9 objects
//LPDIRECT3D9 d3d9 = NULL;
//LPDIRECT3DDEVICE9 d3dDevice = NULL;
//LPD3DXMESH cubeMesh = NULL;
//
//// Function prototypes
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//bool InitDirect3D(HWND hWnd);
//bool LoadMesh(LPCSTR filename, LPD3DXMESH* mesh);
//void DrawCube(const D3DXVECTOR3& position, const D3DXVECTOR3& color);
//void Update(float deltaTime);
//void Render();
//void Cleanup();
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//
//
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = L"DirectX Window Class";
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//
//    RegisterClass(&wc);
//
//    // Create the window
//    HWND hWnd = CreateWindowEx(
//        0,                              // Optional window styles
//        L"DirectX Window Class",                     // Window class
//        L"DirectX Window",               // Window title
//        WS_OVERLAPPEDWINDOW,            // Window style
//        CW_USEDEFAULT, CW_USEDEFAULT,   // Window position
//        WINDOW_WIDTH, WINDOW_HEIGHT,    // Window size
//        NULL,                           // Parent window
//        NULL,                           // Menu
//        hInstance,                      // Instance handle
//        NULL                            // Additional application data
//    );
//
//    if (hWnd == NULL) return 0;
//
//    // Initialize Direct3D
//    if (!InitDirect3D(hWnd))
//    {
//        MessageBox(NULL,
//    }