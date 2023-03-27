#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;

Target* target;
Mesh* mesh;

int railCount = 30;
int railWidth = 3;
int goOutScreen = 14;
float cameraSpeed = 0.1f;

Engine* Eng;

void Update() {
    for (auto go : Eng->gameobjectlist) 
    {
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
        if (go->m_transform.m_position.z > goOutScreen + railWidth) {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z - railWidth * (railCount-1)));
        }


    }

    Collider* collider = go->GetComponent<BoxCollider>();
    Collider* collider2 = go2->GetComponent<BoxCollider>();

    if (collider->IsCollidingWith(collider2))  {
        go->GetComponent<Mesh>()->m_material->Diffuse.r = 10.f;
        printf("EXPLOSION");
    }
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

    /*go = new GameObject();
    go->m_transform.setPosition(D3DXVECTOR3(6.0f, 2.0f, 4.0f));
    go->m_transform.setScale(D3DXVECTOR3(10, 5, 2));
    go->AddComponent<Mesh>();
    Mesh* mesh = go->GetComponent<Mesh>();
    mesh->Init(Eng->d3ddev, Box);*/

    /*target = new Target();
    target->Init(Eng->d3ddev);
    target->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    target->m_transform.setScale(D3DXVECTOR3(0.05f, 0.05f, 0.05f));
    target->m_transform.rotate(30.0f, 30.0f, 30.0f);
    //target->Draw(Eng->d3ddev);
    Eng->gameobjectlist.push_back(target);

    for (int i = 0; i < 50; i++)
    target->Draw(Eng->d3ddev);
    Eng->gameobjectlist.push_back(target);*/

    go = new GameObject();
    go->m_transform.setPosition(D3DXVECTOR3(0.5f, 1.0f, 0.0f));
    go->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go->AddComponent<Mesh>();

    BoxCollider* collider = go->AddComponent<BoxCollider>();

    Mesh* mesh = go->GetComponent<Mesh>();
    mesh->Init(Eng->d3ddev, Box);

    collider->SetBounds(D3DXVECTOR3(-0.5f, -0.5f, -0.5f), D3DXVECTOR3(0.5f, 0.5f, 0.5f));
    Eng->gameobjectlist.push_back(go);

    go2 = new GameObject();
    go2->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
    go2->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go2->AddComponent<Mesh>();

    BoxCollider* collider2 = go2->AddComponent<BoxCollider>();

    Mesh* mesh2 = go2->GetComponent<Mesh>();
    mesh2->Init(Eng->d3ddev, Box);

    collider2->SetBounds(D3DXVECTOR3(-0.5f, -0.5f, -0.5f), D3DXVECTOR3(0.5f, 0.5f, 0.5f));
    Eng->gameobjectlist.push_back(go2);
    


    //for (int i = 0; i < railCount; i++)
    //{
    //    go = new GameObject();
    //    go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + goOutScreen - railWidth * i));
    //    go->AddComponent<Mesh>();
    //    mesh = go->GetComponent<Mesh>();
    //    mesh->Init(Eng->d3ddev, Custom, "rail.x");
    //    Eng->gameobjectlist.push_back(go);
    //}

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
        Update();
    }




    Eng->cleanD3D();

    return msg.wParam;
}