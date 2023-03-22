#include "../Moteur/moteur.h"


GameObject* go;
GameObject* go2;
Mesh* mesh;

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{

    Engine* Eng = new Engine();
    Eng->Init(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);

    go = new GameObject();
    go->m_transform.setPosition(D3DXVECTOR3(6.0f, 2.0f, 4.0f));
    go->m_transform.setScale(D3DXVECTOR3(10, 5, 2));
    go->AddComponent<Mesh>();
    Mesh* mesh = go->GetComponent<Mesh>();
    mesh->Init(Eng->d3ddev, Box);
    Eng->gameobjectlist.push_back(go);

    MSG msg;

    while (TRUE)
    {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
            break;
        Eng->Update();
        Eng->render_frame();
    }

    Eng->cleanD3D();

    return msg.wParam;
}
