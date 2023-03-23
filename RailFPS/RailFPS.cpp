#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;
Target* target;
Mesh* mesh;

Engine* Eng;

void Update() {
    //target->GetComponent<Mesh>()->Update(Eng->d3ddev);
    //target->Draw(Eng->d3ddev);
    //OutputDebugStringA("enter");
}

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{

    Eng = new Engine();
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

    target = new Target();
    target->Init(Eng->d3ddev);
    //target->Draw(Eng->d3ddev);
    Eng->gameobjectlist.push_back(target);

    for (int i = 0; i < 50; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + 14 - 3 * i));
        go->AddComponent<Mesh>();
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
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

        Update();
    }




    Eng->cleanD3D();

    return msg.wParam;
}