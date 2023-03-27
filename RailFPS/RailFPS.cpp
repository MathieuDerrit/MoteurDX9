#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;
Target* target;
Weapon* weapon;
Mesh* mesh;
Collider* collider;

int railCount = 30;
int railWidth = 3;
int goOutScreen = 14;
float cameraSpeed = 0.1f;

Engine* Eng;

void Update() {
    //weapon->m_transform.rotate(.01f, 0.0f, 0.0f);
    /*
    for (auto go : Eng->gameobjectlist) 
    {
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
        if (go->m_transform.m_position.z > goOutScreen + railWidth) {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z - railWidth * (railCount-1)));
        }
    }
    */
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

    target = new Target();
    target->Init(Eng->d3ddev, Balloon);
    target->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
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


    //target->Draw(Eng->d3ddev);
    Eng->gameobjectlist.push_back(weapon);

    //for (int i = 0; i < 50; i++)
    //target->Draw(Eng->d3ddev);
    //Eng->gameobjectlist.push_back(target);
    /*
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + goOutScreen - railWidth * i));
        go->AddComponent<Mesh>();
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
        Eng->gameobjectlist.push_back(go);
    }
*/
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