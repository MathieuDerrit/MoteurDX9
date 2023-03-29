#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;

Shader* shader;

Target* target;
Weapon* weapon;
Mesh* mesh;

int railCount = 30;
int railWidth = 3;
int goOutScreen = 14;
float cameraSpeed = 0.1f;

boolean goTop = true;

Engine* Eng;
float i = 0.0f;
void Update() {

    D3DXVECTOR3 pos = target->m_transform.m_position;

    if (goTop) {
        pos.y += 0.05f;

        if (target->m_transform.m_position.y >= 3.0f) {
            goTop = false;
        }

    }
    else {
        pos.y -= 0.05f;
        if (target->m_transform.m_position.y <= -3.0f) {
            goTop = true;
        }


    }

    target->m_transform.setPosition(pos);

    for (auto go : Eng->gameobjectlist) 
    {
        
        if (go->m_tag != "weapon") {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
            if (go->m_transform.m_position.z > goOutScreen + railWidth && go->m_tag == "rail") {
                go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z - railWidth * (railCount - 1)));
                go->m_transform.rotate(0.0f, 0.0f, 0.0f);
                go->m_transform.rotate(i, 0.0f, 0.0f);
                i += 0.05f;
            }
        }
      
    }
 
}


#ifdef _DEBUG
#include <crtdbg.h>
#endif

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
#ifdef _DEBUG
    _CrtMemState memStateInit;
    _CrtMemCheckpoint(&memStateInit);
#endif

    Eng = new Engine();
    Eng->Init(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);


    go = new GameObject();
    go->m_transform.setPosition(D3DXVECTOR3(2.0f, 2.0f, 0.0f));
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



    
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + goOutScreen - railWidth * i));
        go->AddComponent<Mesh>();
        go->m_tag = "rail";
        if (i % 2 == 0) {
            go->AddComponent<Shader>();
            go->GetComponent<Shader>()->Init(Eng->d3ddev, LPSTR("Color.hlsl"));
        }
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
        Eng->gameobjectlist.push_back(go);
    }

    target = new Target();
    target->Init(Eng->d3ddev, Balloon);
    target->m_transform.setPosition(D3DXVECTOR3(5.0f, 0.0f, 0.0f));
    target->m_transform.setScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
    target->m_transform.rotate(0.0f, 0.0f, 0.0f);

    Eng->gameobjectlist.push_back(target);

    weapon = new Weapon();
    weapon->Init(Eng->d3ddev, Pistol);
    weapon->m_transform.setPosition(D3DXVECTOR3(10.0f, 0.0f, 0.0f));
    weapon->m_transform.setPosition(D3DXVECTOR3(-5.0f, 0.0f, 15.0f));
    weapon->m_transform.setScale(D3DXVECTOR3(10.0f, 10.0f, 10.0f));
    weapon->m_transform.rotate(0.0f, 0.0f, 0.0f);
    weapon->m_transform.rotate(66.0f, 0.0f, 0.0f);
    weapon->m_tag = "weapon";


    Eng->gameobjectlist.push_back(weapon);


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
    delete go;
    delete go2;
    delete Eng;
    delete target;
    delete weapon;


    #ifdef _DEBUG
        _CrtMemState memStateEnd, memStateDiff;
        _CrtMemCheckpoint(&memStateEnd);
        if (_CrtMemDifference(&memStateDiff, &memStateInit, &memStateEnd))
        {
            MessageBoxA(NULL, "MEMORY LEAKS", "DISCLAIMER", 0);
        }
    #endif 
    return msg.wParam;
}
