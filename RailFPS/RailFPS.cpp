#include "../Moteur/moteur.h"


GameObject* go;
GameObject* go2;
Mesh* mesh;
Mesh* mesh2;

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
    for (int i = 0; i < 2; i++) {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(6.0f - 1*i, 2.0f, 4.0f));
        go->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
        go->AddComponent<Mesh>();
        go->AddComponent<Collider>();
        Mesh* mesh = go->GetComponent<Mesh>();
        if (i == 1) {
            mesh->Init(Eng->d3ddev, Box);
        }
        else
        {
            mesh->Init(Eng->d3ddev, Cylinder);
        }
        
        Eng->gameobjectlist.push_back(go);
    }

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
