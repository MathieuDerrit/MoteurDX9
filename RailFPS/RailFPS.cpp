#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;

GameObject* textCanvas;
GameObject* buttonParent;
GameObject* buttonPlay;

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
    
    //AABB* box1 = go->GetComponent<AABB>();
    //AABB* box2 = go2->GetComponent<AABB>();

    //if (AABB::Get()->AABBvsAABB(go->GetComponent<AABB>(), go2->GetComponent<AABB>())) {
    //    
    //    OutputDebugStringA("explosion");
    //}
    //else
    //{
    //    OutputDebugStringA("MEURS");
    //}



    //Button
    if (buttonParent->GetComponent<Button>()->ClickAction("Quit")) {}
    if (buttonPlay->GetComponent<Button>()->ClickAction("Play")) {
        buttonParent->GetComponent<Button>()->drawBox = false;
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
    auto pos = D3DXVECTOR3(2.0f, 2.0f, 0.0f);
    go->m_transform.setPosition(pos);
    go->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go->AddComponent<AABB>();
    go->AddComponent<Mesh>();
    go->AddComponent<Collider>();
    Mesh* mesh = go->GetComponent<Mesh>();
    AABB* co = go->GetComponent<AABB>();
    co->GetPosition(pos);
    pos = go->GetComponent<Collider>()->m_pos;
    mesh->Init(Eng->d3ddev, Box);
    Eng->gameobjectlist.push_back(go);

    go2 = new GameObject();
    auto pos2 = D3DXVECTOR3(2.0f, 1.0f, 0.0f);
    go2->m_transform.setPosition(pos2);
    go2->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go2->AddComponent<AABB>();
    go2->AddComponent<Mesh>();
    go2->AddComponent<Collider>();
    Mesh* mesh2 = go2->GetComponent<Mesh>();
    AABB* co2 = go2->GetComponent<AABB>();
    co2->GetPosition(pos2);
    pos2 = go2->GetComponent<Collider>()->m_pos;
    mesh2->Init(Eng->d3ddev, Box);
    Eng->gameobjectlist.push_back(go2);

    textCanvas = new GameObject();
    auto text = textCanvas->AddComponent<FieldText>();
    text->Init(Eng->d3ddev);
    text->text = "RailFPS";
    text->fontHeight = 100;
    text->textColor = D3DCOLOR_ARGB(120, 120, 255, 60);
    text->size = D3DXVECTOR2(300, 100);
    text->Draw();
    Eng->gameobjectlist.push_back(textCanvas);

    buttonParent = new GameObject();
    auto buttonTest = buttonParent->AddComponent<Button>();
    buttonTest->Init(Eng->d3ddev);
    buttonTest->message = "QUIT";
    //buttonTest->buttonFormat = DT_RIGHT;
    buttonTest->Draw();
    Eng->gameobjectlist.push_back(buttonParent);  
    
    buttonPlay = new GameObject();
    auto Play = buttonPlay->AddComponent<Button>();
    Play->Init(Eng->d3ddev);
    Play->message = "PLAY";
    //Play->buttonFormat = DT_BOTTOM;
    Play->position = D3DXVECTOR2(200, 50);
    Play->Draw();
    Eng->gameobjectlist.push_back(buttonPlay);

    
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
